import numpy as np 
import cv2

# read image
img = cv2.imread('C:/Users/TOBI/Documents/Belajar_Python/PCD_prak/p5/melon.jpeg')
# convert img kedalam HSV dan Lab 
img_hsv = cv2.cvtColor(img, cv2.COLOR_BGR2HSV)
img_lab = cv2.cvtColor(img, cv2.COLOR_BGR2LAB)
# split setiap chanel
l_b, l_g, l_r = cv2.split(img)
l_h, l_s, l_v = cv2.split(img_hsv)
l_l, l_a, l_b = cv2.split(img_lab)

# mask bgr-SUSAH
# low = np.array([10, 100, 160])
# up = np.array([60, 220, 255])
# mask = cv2.inRange(img, low, up)
# output = cv2.bitwise_and(img, img, mask=mask)

# mask hsv - BETTER
low = np.array([10, 190, 150])
up = np.array([25, 255, 255])
mask = cv2.inRange(img_hsv, low, up)
output = cv2.bitwise_and(img, img, mask=mask)

# mask Lab - lumayan
# low = np.array([100, 120, 160])
# up = np.array([230, 150, 220])
# mask = cv2.inRange(img_lab, low, up)
# output = cv2.bitwise_and(img, img, mask=mask)

# Mask l_r
low_l_r = np.array([160])
up_l_r = np.array([255])
mask_l_r = cv2.inRange(l_r, low_l_r, up_l_r)
output_l_r = cv2.bitwise_and(img, img, mask=mask_l_r)
# Mask l_g
low_l_g = np.array([100])
up_l_g = np.array([220])
mask_l_g = cv2.inRange(l_g, low_l_g, up_l_g)
output_l_g = cv2.bitwise_and(img, img, mask=mask_l_g)
# Mask l_b
low_l_b = np.array([10])
up_l_b = np.array([60])
mask_l_b = cv2.inRange(l_b, low_l_b, up_l_b)
output_l_b = cv2.bitwise_and(img, img, mask=mask_l_b)
# ________________________________________________________
# Mask l_h
low_l_h = np.array([150])
up_l_h = np.array([255])
mask_l_h = cv2.inRange(l_h, low_l_h, up_l_h)
output_l_h = cv2.bitwise_and(img, img, mask=mask_l_h)
# Mask l_s
low_l_s = np.array([190])
up_l_s = np.array([255])
mask_l_s = cv2.inRange(l_s, low_l_s, up_l_s)
output_l_s = cv2.bitwise_and(img, img, mask=mask_l_s)
# Mask l_v
low_l_v = np.array([10])
up_l_v = np.array([25])
mask_l_v = cv2.inRange(l_v, low_l_v, up_l_v)
output_l_v = cv2.bitwise_and(img, img, mask=mask_l_v)
# ________________________________________________________
# Mask l_l
low_l_l = np.array([160])
up_l_l = np.array([220])
mask_l_l = cv2.inRange(l_l, low_l_l, up_l_l)
output_l_l = cv2.bitwise_and(img, img, mask=mask_l_l)
# Mask l_a
low_l_a = np.array([120])
up_l_a = np.array([150])
mask_l_a = cv2.inRange(l_a, low_l_a, up_l_a)
output_l_a = cv2.bitwise_and(img, img, mask=mask_l_a)
# Mask l_b
low_l_b = np.array([100])
up_l_b = np.array([230])
mask_l_b = cv2.inRange(l_b, low_l_b, up_l_b)
output_l_b = cv2.bitwise_and(img, img, mask=mask_l_b)

# display
# cv2.imshow("red", mask_l_r) 
# cv2.imshow("green", mask_l_g) 
# cv2.imshow("blue", mask_l_b) 
# cv2.imshow("hue", mask_l_h) 
# cv2.imshow("sat", mask_l_s) 
# cv2.imshow("val", mask_l_v) 
# cv2.imshow("L", mask_l_l) 
# cv2.imshow("a", mask_l_a) 
# cv2.imshow("b", mask_l_b) 
cv2.imshow("hasil_sat", output_l_s) 
cv2.imshow("hasil_HSV", output) 

# cv2.imwrite("red.png", mask_l_r) 
# cv2.imwrite("green.png", mask_l_g) 
# cv2.imwrite("blue.png", mask_l_b) 
# cv2.imwrite("hue.png", mask_l_h) 
# cv2.imwrite("sat.png", mask_l_s) 
# cv2.imwrite("val.png", mask_l_v) 
# cv2.imwrite("L.png", mask_l_l) 
# cv2.imwrite("a.png", mask_l_a) 
# cv2.imwrite("b.png", mask_l_b) 
# cv2.imwrite("hasil_sat.png", output_l_s) 
# cv2.imwrite("hasil_HSV.png", output) 

cv2.waitKey(0)
cv2.destroyAllWindows()