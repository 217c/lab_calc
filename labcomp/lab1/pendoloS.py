"""
Questo programma implementa l'algoritmo di Eulero-Cromer sul sistema di un oscillatore armonico (anche se il programma si chiama pendoloS, qui è un oscillatore.)
"""

# import sys
# import math
import pandas as pd

# Dichiarazione delle funzioni
def eulero_cromer(x0, v0, Tm, Dt, O2):
    N = int(Tm / Dt)
    xn = x0
    vn = v0
    t = 0
    E0 = 0.5 * vn * vn + 0.5 * O2 * xn * xn

    # Liste per raccogliere i dati
    time_data = []
    position_data = []
    velocity_data = []
    energy_data = []
    delta_energy_data = []

    for i in range(N):
        phi = -O2 * xn
        vn += phi * Dt
        xn += vn * Dt
        t += Dt
        Em = 0.5 * vn * vn + 0.5 * O2 * xn * xn
        DE = (Em - E0) / E0
        
        # Aggiungi i dati alle liste
        time_data.append(t)
        position_data.append(xn)
        velocity_data.append(vn)
        energy_data.append(Em)
        delta_energy_data.append(DE)

    # Crea il dataframe con i dati raccolti
    df = pd.DataFrame({
        't[s]': time_data,
        'x[m]': position_data,
        'v[m/s]': velocity_data,
        'DE': delta_energy_data,
        'Em': energy_data
    })

    return df


def eulero(x0, v0, Tm, Dt, O2):
    N = int(Tm / Dt)
    xn = x0
    vn = v0
    t = 0
    E0 = 0.5 * vn * vn + 0.5 * O2 * xn * xn
    print("# t[s], x[m], v[m/s], DE")
    
    for i in range(1, N + 1):
        phi = -O2 * xn
        xn += vn * Dt
        vn += phi * Dt
        t += Dt
        Em = 0.5 * vn * vn + 0.5 * O2 * xn * xn
        DE = (Em - E0) / E0
        print(f"{t} {xn} {vn} {DE} {Em}")


# Inizio del programma principale
if __name__ == "__main__":

    # Impostazione variabili
    O2 = 0.1
    x0 = 3
    v0 = [4, -4, 10, -2, 0, 70, -30]
    Dt = 0.1
    Tm = 100
    
    df_list = []
    for this_v in v0:
        df_list.append(eulero_cromer(x0, this_v, Tm, Dt, O2))
        df_list[-1]["v0"] = this_v
    
    df = pd.concat(df_list)
    df.to_csv("labcomp/lab1/datapy.csv", index = False)
    print(df)
