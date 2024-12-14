import numpy as np
import matplotlib.pyplot as plt
import pandas as pd

cols = [
    "t", 
    "D"
    ]

df = pd.read_csv("data.txt",
                 names=cols,
                 skiprows=1,
                 sep = " ",
                 index_col=False)

print(df)

plt.plot(df.t, df.D, "o")
plt.show()