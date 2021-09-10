import numpy as np
import cv2
# Uncomment
# NO 2 ________________________________________________________________
# read image
a = np.array([1, 2, 3], dtype=np.int)
b = np.array([2, 3, 4], dtype=np.float32)

print(a)
print(b)
c = a-b
print(c)
# error 
# a[a > 1] *= 0.5
# print(a)
b[b > 1] *= 2
print(b)
