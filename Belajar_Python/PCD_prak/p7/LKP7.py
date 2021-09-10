import numpy as np 
import cv2
import math

# Hough line transform
# img1 = cv2.imread('C:/Users/TOBI/Documents/Belajar_Python/PCD_prak/p7/cubes.jpg')
# # cv2.imshow('Gambar kubik', img1)
# gray1 = cv2.cvtColor(img1, cv2.COLOR_BGR2GRAY)
# edges1 = cv2.Canny(gray1, 200, 220, apertureSize=3)
# lines = cv2.HoughLines(edges1, 1, np.pi/180, 119)

# for i in range(0, len(lines)):
#     rho = lines[i][0][0]
#     theta = lines[i][0][1]
#     a = math.cos(theta)
#     b = math.sin(theta)
#     x0 = a*rho
#     y0 = b*rho
#     x1 = int(x0 + 1000*(-b))
#     y1 = int(y0 + 1000*(a))
#     x2 = int(x0 - 1000*(-b))
#     y2 = int(y0 - 1000*(a))
#     cv2.line(img1,(x1,y1),(x2,y2),(0,200,255),2)

# print(lines[0])

# # cv2.imshow('canny', edges1)
# cv2.imshow('Hough line', img1)

# Hough circle transform
img2 = cv2.imread('C:/Users/TOBI/Documents/Belajar_Python/PCD_prak/p7/citrus_1.jpg')
# cv2.imshow('img2', img2)
gray2 = cv2.cvtColor(img2, cv2.COLOR_BGR2GRAY)
# cv2.imshow('gray21', gray2)
gray2 = cv2.medianBlur(gray2, 11)
# cv2.imshow('gray22', gray2)
edges2 = cv2.Canny(gray2, 200, 220, apertureSize=3)
# cv2.imshow('edge', edges2)

circles = cv2.HoughCircles(gray2, cv2.HOUGH_GRADIENT, 1, 20, 
        param1=60, param2=60, minRadius=30, maxRadius=150)

circles = np.uint16(np.around(circles))
for i in circles[0, :]:
    # draw outer circle
    cv2.circle(img2, (i[0], i[1]), i[2], (0,255,0), 2)
    # draw the center of the circle 
    cv2.circle(img2, (i[0], i[1]), 2, (0,0,255), 3)
    print('cx: {}, cy: {}, radius: {}'.format(i[0], i[1], i[2]))

cv2.imshow('Hough Circle', img2)

cv2.waitKey(0)
cv2.destroyAllWindows()