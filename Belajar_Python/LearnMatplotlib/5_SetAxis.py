import numpy as np 
import matplotlib.pyplot as plt

def sinusGenerator(amplitudo, frekuensi, tAkhir, theta):
    t = np.arange(0, tAkhir, 0.1)
    y = amplitudo * np.sin(2*frekuensi*t + np.deg2rad(theta))
    return t,y
# 1. membuat data  
t,y = sinusGenerator(1,1,4,0)

# 2. membuat plot 
plt.plot(t,y)

# set Axis 
# plt.axis([Xmin,Xmax,Ymin,Ymax])
plt.axis([0,4,-2,2])

# 3. menampilkan plot 
plt.show()
