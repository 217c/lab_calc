import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
 
cols = [
    "t", 
    "r_a_x", 
    "r_a_y", 
    "r_b_x", 
    "r_b_y", 
    "v_a_x", 
    "v_a_y", 
    "v_b_x", 
    "v_b_y",
    "phi_a_x", 
    "phi_a_y", 
    "phi_b_x", 
    "phi_b_y",
    "r_ab"
    ]

df = pd.read_csv("data.txt",
                 names=cols,
                 skiprows=1,
                 sep = " ",
                 index_col=False)

# print(df)


fig, axes = plt.subplots(6, 2, figsize=(12, 15))
fig.tight_layout(pad=4.0)

# Loop per creare ogni subplot in funzione di t
for i, col in enumerate(["r_a_x", "r_a_y", "r_b_x", "r_b_y", "v_a_x", "v_a_y", "v_b_x", "v_b_y","phi_a_x", "phi_a_y", "phi_b_x", "phi_b_y"]):
    # Trova l'indice della riga e della colonna del subplot
    row = i // 2
    col_num = i % 2
    ax = axes[row, col_num]
    
    # Traccia il grafico della colonna in funzione di t
    ax.plot(df['t'], df[col], label=col)
    ax.set_xlabel('t')
    ax.set_ylabel(col)
    # ax.legend()
    ax.grid(True)  # Aggiunge la griglia

plt.show()
# posizioni pianeti
# ax2 = axes[6, 1]
# ax2.plot(df['r_a_x'],
#          df['r_a_y'],
#          label='Pianeta A',
#          color='purple')
# ax2.plot(df['r_b_x'], 
#          df['r_b_y'],
#          label='Pianeta B',
#          color="green")
# ax2.plot(0, 0, "yo") # il sole
# ax2.set_xlabel('y')
# ax2.set_ylabel('y')
# ax2.set_xlim(-10,10)
# ax2.set_ylim(-10,10)
# ax2.legend()
# ax2.grid(True)  # Aggiunge la griglia

# distanze
plt.plot(df["t"], df["r_ab"])
plt.ylabel('Distanza fra i pianeti')
plt.xlabel('t')
plt.grid()
plt.show()

# Creazione di una nuova figura per il grafico delle posizioni dei pianeti
plt.figure(figsize=(8, 8))

# Traccia le posizioni dei pianeti
plt.plot(df['r_a_x'], df['r_a_y'], label='Pianeta A', color='purple')
plt.plot(df['r_b_x'], df['r_b_y'], label='Pianeta B', color="green")

# Aggiungi il Sole come punto centrale
plt.plot(0, 0, "yo", label="Sole")  # "yo" rappresenta un punto giallo

# Imposta etichette per gli assi e limiti dell'area visualizzata
plt.xlabel('x')
plt.ylabel('y')

my_limite = 2

plt.xlim(-my_limite, my_limite)
plt.ylim(-my_limite, my_limite)

# Aggiungi una legenda e una griglia
plt.legend()
plt.grid(True)

# Mostra il grafico
plt.show()