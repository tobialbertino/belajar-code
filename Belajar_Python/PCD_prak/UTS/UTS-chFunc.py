import numpy as np 
import matplotlib.pyplot as plt 
import cv2

# apel ganjil
img = cv2.imread('C:/Users/TOBI/Documents/Belajar_Python/PCD_prak/UTS/apel_ganjil.jpg')

# gaussian kernel untuk blur gambar dan mempertenal informasi garis
gaus5 = cv2.GaussianBlur(img, (5,5), 0)
gaus15 = cv2.GaussianBlur(img, (15,15), 0)

# Convert ke BGR 
gray5 = cv2.cvtColor(gaus5, cv2.COLOR_BGR2GRAY)
# gray15 = cv2.cvtColor(gaus15, cv2.COLOR_BGR2GRAY)

test = cv2.Canny(gray5, 10, 255, apertureSize=3)
cv2.imshow('test', cv2.resize(test, (940, 629)))


cv2.waitKey(0)
cv2.destroyAllWindows()