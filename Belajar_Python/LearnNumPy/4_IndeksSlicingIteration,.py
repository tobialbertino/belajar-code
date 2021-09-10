import numpy as np 

a = np.arange(10)**2

print(a)

# mengambil nilai
print('element ke 1 dari a adalah', a[0])
print('element ke 7 dari a adalah', a[6])
print('element ke akhir dari a adalah', a[-1])

# slicing
print('element dari 1-6 adalah', a[0:6])
print('element dari 4-akhir adalah', a[3:])
print('element dari awal-5 adalah', a[:5])

# Iterasi
for i in a:
    print('value = ',i)