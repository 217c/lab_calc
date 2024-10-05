import numpy as np
import matplotlib.pyplot as plt
import pandas as pd

df = pd.read_csv("labcomp/lab1/datapy.csv")

print(df)

# Group by the 'x0' column
groups = df.groupby('v0')

# Create subplots: 1 row for t vs x and 1 row for t vs v
fig, axs = plt.subplots(3, 1, figsize=(12, 10))  # 2 rows, 1 column

# Plot t vs x for each x0 condition
for name, group in groups:
    axs[0].plot(group['t[s]'], group['x[m]'], label=f'v0 = {name}')
    axs[1].plot(group['t[s]'], group['v[m/s]'], label=f'v0 = {name}')
    axs[2].plot(group['x[m]'], group['v[m/s]'], label=f'v0 = {name}')

# Set titles and labels for the subplots
axs[0].set_title('Posizione')
axs[0].set_xlabel('t [s]')
axs[0].set_ylabel('x [m]')
axs[0].grid()
axs[0].legend()

axs[1].set_title('Velocità')
axs[1].set_xlabel('t [s]')
axs[1].set_ylabel('v [m/s]')
axs[1].grid()
axs[1].legend()

axs[2].set_title('Spazio delle fasi')
axs[2].set_xlabel('x [m]')
axs[2].set_ylabel('v [m/s]')
axs[2].grid()
axs[2].legend()

# Adjust layout
plt.tight_layout()

# Show the plot
plt.show()
