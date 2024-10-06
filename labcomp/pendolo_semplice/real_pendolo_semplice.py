"""
Questo programma implementa l'algoritmo di Eulero-Cromer sul sistema di un PENDOLO SEMPLICE.
"""

# import sys
import math
import numpy as np
import pandas as pd

def phi_eq(g, l, thetan):
    return - (g * np.sin(thetan))/l

def v_next(vn, phi, delta_t):
    return vn + phi*delta_t

def theta_next(thetan, vn, delta_t):
    return thetan + vn*delta_t

def my_eulero_cromer(theta0, v0, g, l, delta_t, t_max):
    n = int(t_max / delta_t)
    thetan = theta0
    vn = v0
    t = 0
    
    # Liste per raccogliere i dati
    time_data = []
    position_data = []
    velocity_data = []
    acceleration_data = []
    # sin_data = []
    
    # accelerazione iniziale
    phi    = phi_eq(g, l, thetan)
    
    # Aggiungi il tempo 0 dati alle liste
    time_data.append(round(t,4))
    position_data.append(round(thetan,4))
    velocity_data.append(round(vn,4))
    acceleration_data.append(round(phi, 4))
    # sin_data.append(round(np.sin(thetan), 4))
    
    # energy_data = []
    # delta_energy_data = []
    
    for i in range(n):
        
        # aggiornamento dello stato cinematico
        vn     = v_next(vn, phi, delta_t)
        thetan = theta_next(thetan, vn, delta_t)
        
        # accelerazione dopo l'aggiornamento dello stato cinematico
        phi    = phi_eq(g, l, thetan)
        
        t += delta_t
        

        # Aggiungi i dati alle liste
        time_data.append(round(t,4))
        position_data.append(round(thetan,6))
        velocity_data.append(round(vn,4))
        acceleration_data.append(round(phi, 6))
        # sin_data.append(round(np.sin(thetan), 6))
        
        
    # Crea il dataframe con i dati raccolti
    df = pd.DataFrame({
        't[s]': time_data,
        'theta[rad]': position_data,
        'v[rad/s]': velocity_data,
        'a[rad/s^2]': acceleration_data,
        # 'sin_theta': sin_data
    })

    return df

# Inizio del programma principale
if __name__ == "__main__":

    # Impostazione variabili
    g = 9.81
    l = 1
    theta0 = math.radians(3)
    v0 = [0,1,2,4,5,-3,-6.262,-6.263,-2]+[x/100 for x in list(range(620, 630, 1))]+[x/1000 for x in list(range(6261, 6264, 1))] #[6.2, 6.3]
    delta_t = 0.001
    t_max = 5
    
    df_list = []
    for this_v0 in v0:
        df_list.append(my_eulero_cromer(theta0, this_v0, g, l, delta_t, t_max) )
        df_list[-1]["v0"] = this_v0
    
    df = pd.concat(df_list)
    df.to_csv("labcomp/pendolo_semplice/pendolo_datapy.csv", index = False)
    print(df)
