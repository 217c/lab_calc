import numpy as np
import matplotlib.pyplot as plt
import pandas as pd

df = pd.read_csv("labcomp/pendolo_semplice/pendolo_datapy.csv")

print(df)

# Group by the 'x0' column
groups = df.groupby('v0')

# Create subplots: 1 row for t vs x and 1 row for t vs v
fig, axs = plt.subplots(2, 2, figsize=(12, 10))  # 2 rows, 1 column

# Plot t vs x for each x0 condition
for name, group in groups:
    axs[0,0].plot(group['t[s]'], group['theta[rad]'], label=f'v0 = {name}')
    axs[0,1].plot(group['t[s]'], group['v[rad/s]'], label=f'v0 = {name}')
    axs[1,0].plot(group['t[s]'], group['a[rad/s^2]'], label=f'v0 = {name}')
    # axs[3].plot(group['t[s]'], group['sin_theta'], label=f'v0 = {name}')
    axs[1,1].plot(group['theta[rad]'], group['v[rad/s]'], label=f'v0 = {name}')

# Set titles and labels for the subplots
axs[0,0].set_title('Posizione')
axs[0,0].set_xlabel('t [s]')
axs[0,0].set_ylabel('theta [rad]')
axs[0,0].grid()
axs[0,0].legend()

axs[0,1].set_title('Velocità')
axs[0,1].set_xlabel('t [s]')
axs[0,1].set_ylabel('v [rad/s]')
axs[0,1].grid()
axs[0,1].legend()

axs[1,0].set_title('Accelerazione')
axs[1,0].set_xlabel('t [s]')
axs[1,0].set_ylabel('a [rad/s^2]')
axs[1,0].grid()
axs[1,0].legend()

# axs[3].set_title('Seno di theta')
# axs[3].set_xlabel('t [s]')
# axs[3].set_ylabel('sin theta')
# axs[3].grid()
# axs[3].legend()

axs[1,1].set_title('Spazio delle fasi')
axs[1,1].set_xlabel('theta [rad]')
axs[1,1].set_ylabel('v [rad/s]')
axs[1,1].grid()
axs[1,1].legend()


# Adjust layout
plt.tight_layout()

# Show the plot
# plt.show()


## plot del solo spazio delle fasi
# Create subplots: 1 row for t vs x and 1 row for t vs v
fig, axs = plt.subplots(1, 1, figsize=(12, 10))  # 2 rows, 1 column
for name, group in groups:
    axs.plot(group['theta[rad]'], group['v[rad/s]'], label=f'v0 = {name}')

axs.set_title('Spazio delle fasi')
axs.set_xlabel('theta [rad]')
axs.set_ylabel('v [rad/s]')
axs.grid()
axs.legend()

# Adjust layout
plt.tight_layout()

# Show the plot
plt.show()