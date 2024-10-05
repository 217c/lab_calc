import numpy as np
import matplotlib.pyplot as plt

# import os
# cwd = os.getcwd()
# print(cwd)


t, x, v, DE, E = np.loadtxt("labcomp/lab1/datapy.txt", unpack=True) # questi sono i dati da C


# Create a figure with 4 subplots (2 rows, 2 columns)
fig, axs = plt.subplots(2, 2, figsize=(12, 10))  # 2 rows and 2 columns of plots

# Plot t vs x on the first subplot
axs[0, 0].plot(t, x, "-o", linewidth=2, markersize=2)
axs[0, 0].set_title("Posizione")
axs[0, 0].set_xlabel('t')
axs[0, 0].set_ylabel('x')
axs[0, 0].grid()

# Plot t vs v on the second subplot
axs[0, 1].plot(t, v, "-s", linewidth=2, markersize=2)
axs[0, 1].set_title("Velocità")
axs[0, 1].set_xlabel('t')
axs[0, 1].set_ylabel('v')
axs[0, 1].grid()

# Plot t vs DE on the third subplot
axs[1, 0].plot(t, DE, "-^", linewidth=2, markersize=2)
axs[1, 0].set_title("Delta E")
axs[1, 0].set_xlabel('t')
axs[1, 0].set_ylabel('DE')
axs[1, 0].grid()

# Plot t vs E on the fourth subplot
axs[1, 1].plot(t, E, "-d", linewidth=2, markersize=2)
axs[1, 1].set_title("E (per unità di massa)")
axs[1, 1].set_xlabel('t')
axs[1, 1].set_ylabel('E')
axs[1, 1].grid()

# Adjust layout so plots don't overlap
plt.tight_layout()

# Show the plot
plt.show()