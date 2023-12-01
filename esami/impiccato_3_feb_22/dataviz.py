import numpy as np
import matplotlib.pyplot as plt

v1, v2, v3 = np.loadtxt("esami/impiccato_3_feb_22/tentativi.txt", unpack=True)


plt.bar(v1, v3)
plt.show()