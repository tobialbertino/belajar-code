import numpy as np 

# list python
a = [1,2,3,4,5]
b = [6,7,8,9,10]

# array NumPy
anp = np.array([1,2,3,4,5])
bnp = np.array([6,7,8,9,10])
# ELEMENTWISE operation dengan numPy
# penjumlahan
hasil = anp + bnp

# pengurangan
hasil = anp - bnp

# perkalian
hasil = anp * bnp 

# pembagian
hasil = anp / bnp

# kuadrat
hasil = anp**2

# multiDimensi array NumPy
c = np.array(( [1,2,3], [4,5,6] ))
d = np.array(( [7,8,9], [-1,-2,-3] ))

hasil = c + d
hasil = c * d
print(hasil)