import numpy as np
import matplotlib.pyplot as plt

turn_iter, granelli_tot, init_sand, grid_center = np.loadtxt("esami/sandpile/history.dat", unpack=True)

# faceted plot
f, (ax1, ax2, ax3) = plt.subplots(3, 1, sharex=True)
ax1.plot(turn_iter, granelli_tot)
ax1.set_title("Granelli totali")

ax2.plot(turn_iter, init_sand)
ax2.set_title("Granelli nella casella iniziale")

ax3.plot(turn_iter, grid_center)
ax3.set_title("Granelli nella casella centrale")

plt.show()