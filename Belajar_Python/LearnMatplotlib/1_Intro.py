import numpy as np 
import matplotlib.pyplot as plt 


PI = np.pi
sudut = np.linspace(0, 2*PI, 100)
radius = 5

x = radius*np.cos(sudut)
y = radius*np.sin(sudut)

plt.plot(x,y)
plt.show()