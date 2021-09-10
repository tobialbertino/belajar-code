import numpy as np 
import cv2

# Median Blur  
img = cv2.imread("lenna.png", 0)
median = cv2.medianBlur(img,5)
cv2.imshow("original", img)
cv2.imshow("median", median)
cv2.waitKey(0)

# FIlter Spesial 
img = cv2.imread("lenna.png", 0)
kernel = np.array([[0, -1, 0],
 [-1, 4, -1],
 [0, -1, 0]])
dst = cv2.filter2D(img,-1,kernel)
cv2.imshow("original", img)
cv2.imshow("result", dst)
cv2.waitKey(0)

# Gaussian Noise 
img = cv2.imread("lenna.png")
gauss = np.random.normal(0,1,img.size)
gauss = gauss.reshape(img.shape[0], img.shape[1]).astype(np.uint8)
gauss.reshape(img.shape[0],img.shape[1],img.shape[2]).astype('uint8')
img_gauss = cv2.add(img,gauss)
cv2.imshow("original", img)
cv2.imshow('Gaussian noise', img_gauss)
cv2.waitKey(0)