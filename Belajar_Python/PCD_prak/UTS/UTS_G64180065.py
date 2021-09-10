import numpy as np 
import matplotlib.pyplot as plt 
import cv2
# No 1_____________________________________________________________________________________
# apel ganjil
img = cv2.imread('C:/Users/TOBI/Documents/Belajar_Python/PCD_prak/UTS/apel_ganjil.jpg')

# gaussian kernel untuk blur gambar dan mempertenal informasi garis
gaus5 = cv2.GaussianBlur(img, (5,5), 0)
gaus15 = cv2.GaussianBlur(img, (15,15), 0)

# Convert ke BGR 
gray5 = cv2.cvtColor(gaus5, cv2.COLOR_BGR2GRAY)
gray15 = cv2.cvtColor(gaus15, cv2.COLOR_BGR2GRAY)

# Gradient calculation, dengan operator Sobel/Prewitt
sobel_x = np.array(([-1, 0, 1],
                    [-2, 0, 2],
                    [-1, 0, 1]))
sobel_y = np.array(([-1, -2, -1],
                    [0, 0, 0],
                    [1, 2, 1]))
# dengan blur 5x5
# edge_5x = cv2.filter2D(gray5, -1, sobel_x)
# edge_5y = cv2.filter2D(gray5, -1, sobel_y)
# edge_5xy = cv2.add(edge_5x, edge_5y)
# cv2.imshow("deteksi sumbu 5x", cv2.resize(edge_5x, (940, 629)))
# cv2.imshow("deteksi sumbu 5y", cv2.resize(edge_5y, (940, 629)))
# cv2.imshow("deteksi sumbu 5xy", cv2.resize(edge_5xy, (940, 629)))

# dengan blur 15x15
# edge_15x = cv2.filter2D(gray15, -1, sobel_x)
# edge_15y = cv2.filter2D(gray15, -1, sobel_y)
# edge_15xy = cv2.add(edge_15x, edge_15y)
# cv2.imshow("deteksi sumbu 15x", cv2.resize(edge_15x, (940, 629)))
# cv2.imshow("deteksi sumbu 15y", cv2.resize(edge_15y, (940, 629)))
# cv2.imshow("deteksi sumbu 15xy", cv2.resize(edge_15xy, (940, 629)))

# dengan fungsi 
# Gradient calculation
def sobel_filters(img):
    global sobel_x
    global sobel_y
    
    Ix = cv2.filter2D(img, -1, sobel_x)
    Iy = cv2.filter2D(img, -1, sobel_y)
    
    G = np.hypot(Ix, Iy)
    G = G / G.max() * 255
    G = G.astype(np.uint8)
    theta = np.arctan2(Iy, Ix)
    
    return (G, theta)

# Non-maximum suppression
def non_max_suppression(img, D):
    M, N = img.shape
    Z = np.zeros((M,N), dtype=np.int32)
    angle = D * 180. / np.pi
    angle[angle < 0] += 180

    for i in range(1,M-1):
        for j in range(1,N-1):
            try:
                q = 255
                r = 255
                
                #angle 0
                if (0 <= angle[i,j] < 22.5) or (157.5 <= angle[i,j] <= 180):
                    q = img[i, j+1]
                    r = img[i, j-1]
                #angle 45
                elif (22.5 <= angle[i,j] < 67.5):
                    q = img[i+1, j-1]
                    r = img[i-1, j+1]
                #angle 90
                elif (67.5 <= angle[i,j] < 112.5):
                    q = img[i+1, j]
                    r = img[i-1, j]
                #angle 135
                elif (112.5 <= angle[i,j] < 157.5):
                    q = img[i-1, j-1]
                    r = img[i+1, j+1]

                if (img[i,j] >= q) and (img[i,j] >= r):
                    Z[i,j] = img[i,j]
                else:
                    Z[i,j] = 0

            except IndexError as e:
                pass
    Z = Z.astype(np.uint8)
    return Z

# Double threshold
def threshold(img, lowThresh=50, highThresh=255):
    
    highThreshold = highThresh;
    lowThreshold = lowThresh;
    
    M, N = img.shape
    res = np.zeros((M,N), dtype=np.uint8)
    
    weak = np.int32(75)
    strong = np.int32(255)
    
    strong_i, strong_j = np.where(img >= highThreshold)
    zeros_i, zeros_j = np.where(img < lowThreshold)
    
    weak_i, weak_j = np.where((img <= highThreshold) & (img >= lowThreshold))
    
    res[strong_i, strong_j] = strong
    res[zeros_i, zeros_j] = 0
    res[weak_i, weak_j] = weak
    
    return (res)

# Edge Tracking by Hysteresis
def hysteresis(img, weak, strong=255):
    M, N = img.shape  
    for i in range(1, M-1):
        for j in range(1, N-1):
            if (img[i,j] == weak):
                try:
                    if ((img[i+1, j-1] == strong) or (img[i+1, j] == strong) or (img[i+1, j+1] == strong)
                        or (img[i, j-1] == strong) or (img[i, j+1] == strong)
                        or (img[i-1, j-1] == strong) or (img[i-1, j] == strong) or (img[i-1, j+1] == strong)):
                        img[i, j] = strong
                    else:
                        img[i, j] = 0
                except IndexError as e:
                    pass
    img = img.astype(np.uint8)
    return img
# Main
g, theta = sobel_filters(gray5)
cv2.imshow('g', cv2.resize(g, (940, 629)))

non_max_s = non_max_suppression(g, theta)
cv2.imshow('non_max_s', cv2.resize(non_max_s, (940, 629)))

res = threshold(non_max_s, 70, 150)
cv2.imshow('res', cv2.resize(res, (940, 629)))

hyst = hysteresis(res, 25)
cv2.imshow('hysts', cv2.resize(hyst, (940, 629)))

cv2.imwrite('apel_Gaus5.png', gaus5)
cv2.imwrite('apel_Gaus15.png', gaus15)
# _____________________________________________________________________________________
# No2 
# # Akan digunakan fungsi canny dari library cv2
# canny = cv2.Canny(gray5, 70, 150)
# cv2.imshow('canny', cv2.resize(canny, (940, 629)))
# # Fungsi sobel x & y yg dikonversi kembali menjadi uint8 
# sobelx64f = cv2.Sobel(gray5, cv2.CV_64F, 1, 0, 3)
# sobely64f = cv2.Sobel(gray5, cv2.CV_64F, 0, 1, 3)
# sobel_x = np.absolute(sobelx64f)
# sobel_y = np.absolute(sobely64f)
# sobel_xy = np.hypot(sobel_x, sobel_y)
# sobel_xy = sobel_xy / sobel_xy.max() * 255
# sobel_xy = sobel_xy.astype(np.uint8)
# cv2.imshow('sobel', cv2.resize(sobel_xy, (940, 629)))

cv2.waitKey(0)
cv2.destroyAllWindows()