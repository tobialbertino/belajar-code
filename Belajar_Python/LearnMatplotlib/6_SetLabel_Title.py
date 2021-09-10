import numpy as np 
import matplotlib.pyplot as plt 

def sinusGenerator(amplitudo, frekuensi, tAkhir, theta):
    t = np.arange(0, tAkhir, 0.1)
    y = amplitudo * np.sin(2*frekuensi*t + np.deg2rad(theta))
    return t,y

# 1. membuat data  
t,y = sinusGenerator(1,1,4,0)

# membaut plot
judul = 'Grafik Sinusoida\n'
rumus = r'$ \mathcal{Y} = A.sin(2 \omega t + \theta) $' + '\n'
parameter1 = r'$ A =  $' + '1' + ' cm, '
parameter2 = r'$ \omega = $' + '1' + r'$ \mathit{Hz}$' + ', '
parameter3 = r'$ \theta = $' + '0' + r'$^{o}$'

plt.plot(t,y)

plt.title(judul + rumus + parameter1 + parameter2 + parameter3)

plt.xlabel('waktu(detik)') # label
plt.ylabel('magnitudo(cm)')


# menampilkan plot
plt.show()