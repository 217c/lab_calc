import numpy as np
import matplotlib.pyplot as plt

# v1, v2, v3, w1, w2, w3 = np.loadtxt("/home/carlo/projects/lab_calc/lezioni/EX7/coordinate_prof.dat", unpack=True)
v1, v2, v3, w1, w2, w3 = np.loadtxt("/home/carlo/projects/lab_calc/lezioni/EX7/coordinate.dat", unpack=True)

# print(v1)
# print(w1)

# plt.plot(v1, v3, "or")
# plt.show()

# plt.plot(v1, w1, "or")
# plt.show()

# plt.plot(v2, w2, "or")
# plt.show()

# plt.plot(v3, w3, "or")
# plt.show()

# plot 4: faceted plot
f, (ax1, ax2, ax3, ax4) = plt.subplots(4, 1, sharex=True)
ax1.plot(v1, v3, "or")
# ax1.set_title("Ore lavorate")

ax2.plot(v1, w1, "or")
# ax2.set_title("Euro incassati")

ax3.plot(v2, w2, "or")
# ax3.set_title("Media €/h")

ax4.plot(v3, w3, "or")

plt.show()