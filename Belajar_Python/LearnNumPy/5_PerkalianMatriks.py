import numpy as np 

a = np.array((  [1,2], [3,4] ))

b = np.ones([2, 2])

print('matriks a :')
print(a)
print('matriks b :')
print(b)

# perkalian matriks
c1 = np.dot(a, b)
c2 = a.dot(b)

print('matriks c2 :')
print(c2)