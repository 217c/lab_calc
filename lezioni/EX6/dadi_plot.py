import numpy as np
import matplotlib.pyplot as plt

k, k_succ, succ_freq = np.loadtxt("lezioni/EX6/istogramma.dat", unpack = True)

# print(prob)
# print(k)

plt.bar(k, succ_freq)
plt.show()