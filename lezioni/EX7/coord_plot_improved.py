"""
Questo programma lancia dei warning ma è tutto ok.
"""

import numpy as np
import pandas as pd

import matplotlib.pyplot as plt
import matplotlib.animation as animation

df = pd.read_table("/home/carlo/projects/lab_calc/lezioni/EX7/coordinate_tuttigliangoli.dat",
                   delimiter = " ",
                   header = None,
                   names = ["ang", "v1", "v2", "v3", "w1", "w2", "w3"])

# print(df)

data = df.groupby(["ang"])[["v1", "v2", "v3", "w1", "w2", "w3"]].agg(list).reset_index()

# print(data.loc[0][1]) # this is v1 at ang 0

f, (ax1, ax2, ax3, ax4) = plt.subplots(1, 4, sharex = True)

ax1.plot(data.loc[0][1], data.loc[0][3], "or")

ax2.plot(data.loc[0][1], data.loc[0][4], "or")

ax3.plot(data.loc[0][2], data.loc[0][5], "or")

ax4.plot(data.loc[0][3], data.loc[0][6], "or")


def update(frame):
    # for each frame
    ax1.clear()
    ax2.clear()
    ax3.clear()
    ax4.clear()
    
    # update the scatter plots:
    ax1.plot(data.loc[frame][1], data.loc[frame][3], "or")

    ax2.plot(data.loc[frame][1], data.loc[frame][4], "or")

    ax3.plot(data.loc[frame][2], data.loc[frame][5], "or")

    ax4.plot(data.loc[frame][3], data.loc[frame][6], "or")
    
    ax1.set_title(f'{frame}')
    
    return (ax1, ax2, ax3, ax4)

ani = animation.FuncAnimation(fig=f, func=update,
                            interval=5
                              )
plt.show()