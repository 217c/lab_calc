import numpy as np
import matplotlib.pyplot as plt

# import data
rank, hours, euros, guy_n, mean = np.loadtxt("rank.dat", unpack = True)

"""
# plot 1: ore lavorate per ciascun commesso
plt.bar(height = hours, x = guy_n)
plt.xticks(range(len(rank)))
plt.xlabel("Guy ID")
plt.ylabel("Ore lavorate")
#plt.show()

# plot 2: euro incassati per ciascun commesso
plt.bar(height = euros, x = guy_n)
plt.xticks(range(len(rank)))
plt.xlabel("Guy ID")
plt.ylabel("Euro incassati")
#plt.show()

# plot 3: media oraria per ciascun commesso
plt.bar(height = mean, x = guy_n)
plt.xticks(range(len(rank)))
plt.xlabel("Guy ID")
plt.ylabel("Media €/h")
#plt.show()
"""

# plot 4: faceted plot
f, (ax1, ax2, ax3) = plt.subplots(3, 1, sharex=True)
ax1.bar(height = hours, x = guy_n)
ax1.set_title("Ore lavorate")

ax2.bar(height = euros, x = guy_n)
ax2.set_title("Euro incassati")

ax3.bar(height = mean, x = guy_n)
ax3.set_title("Media €/h")

plt.show()
