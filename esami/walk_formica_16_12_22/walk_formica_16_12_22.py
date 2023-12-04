import numpy as np
import matplotlib.pyplot as plt

n_count, h = np.loadtxt("esami/walk_formica_16_12_22/histo_H.txt",
                        unpack=True)

plt.bar(h, n_count)
# plt.show()

plt.savefig("freqformica.png")