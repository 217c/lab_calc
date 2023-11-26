import numpy as np
import matplotlib.pyplot as plt

v1, v2, v3, w1, w2, w3 = np.loadtxt("/home/carlo/projects/lab_calc/lezioni/EX7/coordinate.dat", unpack=True)

# print(v1)
# print(w1)

# plt.plot(v3, v1, "or")
# plt.show()

plt.plot(w1, v1, "or")
plt.show()