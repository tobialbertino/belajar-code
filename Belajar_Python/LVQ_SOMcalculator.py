import numpy as np 
import math

def euclidean_distance(row1, row2):
	distance = 0.0
	for i in range(len(row1)):
		distance += (row1[i] - row2[i])**2
	return distance

w1 = np.array([0.2 ,0.6, 0.5, 0.9])
w2 = np.array([0.8 ,0.4, 0.7, 0.3])
i1 = np.array([1, 1, 1, 0]) 
i2 = np.array([1, 0, 1, 1]) 
i3 = np.array([0, 1, 1, 0]) 
i4 = np.array([0, 0, 1, 1])

# i1 
d1 = euclidean_distance(i1, w1)
d2 = euclidean_distance(i1, w2)
# print(d1)
# print(d2)
w2 = w2 + (0.6 * (i1 - w2))
# print(w2)

# i2 
d1 = euclidean_distance(i2, w1)
d2 = euclidean_distance(i2, w2)
# print(d1)
# print(d2)
w1 = w1 + (0.6 * (i2 - w1))
# print(w1)

# i3 
d1 = euclidean_distance(i3, w1)
d2 = euclidean_distance(i3, w2)
# print(d1)
# print(d2)
w2 = w2 + (0.6 * (i3 - w2))
# print(w2)

# i4 
d1 = euclidean_distance(i4, w1)
d2 = euclidean_distance(i4, w2)
# print(d1)
# print(d2)
w1 = w1 + (0.6 * (i4 - w1))
# print(w1)

# i1, t=5 
d1 = euclidean_distance(i1, w1)
d2 = euclidean_distance(i1, w2)
# print(d1)
# print(d2)
w2 = w2 + ((0.5*0.6) * (i1 - w2))
# print(w2)

# i2, t=6 
d1 = euclidean_distance(i2, w1)
d2 = euclidean_distance(i2, w2)
# print(d1)
# print(d2)
w1 = w1 + ((0.5*0.6) * (i2 - w1))
# print(w1)

# i3, t=7 
d1 = euclidean_distance(i3, w1)
d2 = euclidean_distance(i3, w2)
# print(d1)
# print(d2)
w2 = w2 + ((0.5*0.6) * (i3 - w2))
# print(w2)

# i4, t=8 
d1 = euclidean_distance(i4, w1)
d2 = euclidean_distance(i4, w2)
print(d1)
print(d2)
w1 = w1 + ((0.5*0.6) * (i4 - w1))
print(w1)
print(w2)