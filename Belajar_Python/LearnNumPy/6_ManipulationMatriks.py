import numpy as np
a = np.array((
    [1,2,3],
    [4,5,6]
))

print('matriks a dengan ukuran:', a.shape)
print(a)

# transpose
print('transpose matriks a:')
print(a.transpose())
print(np.transpose(a))
print(a.T)

# flatten array, vector baris
print('flatten matriks a:')
print(a.ravel())
print(np.ravel(a))

# reshape matriks, urutan indeks, jumlah harus sama
print('reshape matriks a:')
print(a.reshape(3, 2))

# resize matriks, MERUBAH matriks a
print('resize matriks a:')
a.resize(3, 2)
print(a)