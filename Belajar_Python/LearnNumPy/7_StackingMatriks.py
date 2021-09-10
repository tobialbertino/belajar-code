import numpy as np

a = np.array([1,2,3])
b = np.array([4,5,6])

aMat = np.zeros( (2,3) ) # Ukuran matriks harus mirip
bMat = np.ones( (2,3) )

# Stacking Matrik
c = np.hstack( (a,b) )
d = np.vstack( (a,b) )

cMat = np.hstack( (aMat,bMat) )
dMat = np.vstack( (aMat,bMat) )

print(dMat)