import numpy as np 
import cv2

def mask_1ch(img, chanel, low, up):
    low = np.array([low])
    up = np.array([up])
    mask = cv2.inRange(chanel, low, up)
    output = cv2.bitwise_and(img, img, mask=mask)
    return mask, output

# read image
img = cv2.imread('C:/Users/TOBI/Documents/Belajar_Python/PCD_prak/p6/tomato.jpg')
# convert img kedalam HSV dan Lab 
img_hsv = cv2.cvtColor(img, cv2.COLOR_BGR2HSV)
img_lab = cv2.cvtColor(img, cv2.COLOR_BGR2LAB)
# split setiap chanel
l_B, l_g, l_r = cv2.split(img)
l_v, l_s, l_h = cv2.split(img_hsv)
l_b, l_a, l_l = cv2.split(img_lab)

# mask bgr- kurang
# low = np.array([1, 0, 90])
# up = np.array([230, 230, 255])
# mask = cv2.inRange(img, low, up)
# output = cv2.bitwise_and(img, img, mask=mask)

# mask hsv - no
# low = np.array([0, 20, 50])
# up = np.array([195, 255, 254])
# mask = cv2.inRange(img_hsv, low, up)
# output = cv2.bitwise_and(img, img, mask=mask)

# mask Lab - better
low = np.array([10, 130, 130])
up = np.array([235, 210, 190])
mask = cv2.inRange(img_lab, low, up)
output = cv2.bitwise_and(img, img, mask=mask)
# RGB 
mask_r, output_r = mask_1ch(img, l_r, 80, 253)
mask_g, output_g = mask_1ch(img, l_g, 0, 230)
mask_B, output_B = mask_1ch(img, l_B, 0, 230)
# HSV 
mask_h, output_h = mask_1ch(img, l_h, 50, 254)
mask_s, output_s = mask_1ch(img, l_s, 20, 255)
mask_v, output_v = mask_1ch(img, l_v, 1, 195)
# Lab 
mask_l, output_l = mask_1ch(img, l_l, 130, 190)
mask_a, output_a = mask_1ch(img, l_a, 130, 210) # Selected
mask_b, output_b = mask_1ch(img, l_b, 10, 235)

# Do morphology
# erotion 
# Dilation
# kernel_d = np.ones((2, 2), np.uint8)
# kernel_e = np.ones((5, 5), np.uint8)
# dilation = cv2.dilate(mask_a, kernel_d, iterations=1)
# erotion = cv2.erode(dilation, kernel_e, iterations=1)
# output_final = cv2.bitwise_and(img, img, mask=erotion)
# percobaan 2 
kernel_e = np.ones((4, 4), np.uint8)
kernel_d = np.ones((2, 2), np.uint8)
erotion = cv2.erode(mask_a, kernel_e, iterations=1)
dilation = cv2.dilate(erotion, kernel_d, iterations=1)
# Hasil akhir
output_final = cv2.bitwise_and(img, img, mask=dilation)

cv2.imshow('dilation', dilation)
cv2.imshow('erotions', erotion)
cv2.imshow('output final', output_final)

cv2.imshow('img', img)
# show /chanel 
# cv2.imshow('r', l_r)
# cv2.imshow('g', l_g)
# cv2.imshow('B', l_B)
# cv2.imshow('h', l_h)
# cv2.imshow('s', l_s)
# cv2.imshow('v', l_v)
# cv2.imshow('L', l_l)
# cv2.imshow('a', l_a)
# cv2.imshow('b', l_b)
# Mask R,G,B 
# cv2.imshow('r', mask_r)
# cv2.imshow('g', mask_g)
# cv2.imshow('B', mask_B)
# Mask H,S,V
# cv2.imshow('h', mask_h)
# cv2.imshow('s', mask_s)
# cv2.imshow('v', mask_v)
# Mask L,a,b
# cv2.imshow('L', mask_l)
cv2.imshow('a', mask_a)
# cv2.imshow('b', mask_b)
# cv2.imshow('test', mask)

# cv2.imwrite('tomato_HSV.png', img_hsv)
# cv2.imwrite('tomato_Lab.png', img_lab)

cv2.waitKey(0)
cv2.destroyAllWindows()