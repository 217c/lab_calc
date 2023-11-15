import numpy as np
import matplotlib.pyplot as plt

k, prob = np.loadtxt("lezioni/EX6/bernoulli.dat", unpack = True)

# print(prob)
# print(k)

plt.bar(k, prob)
plt.show()