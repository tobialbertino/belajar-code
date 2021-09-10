import numpy as np
import cv2
from math import sqrt, exp
import matplotlib.pyplot as plt

def distance(point1, point2):
    return sqrt((point1[0] - point2[0]) ** 2 + (point1[1] - point2[1]) ** 2)

def gaussianHP(D0, imgShape):
    base = np.zeros(imgShape[:2])
    rows, cols = imgShape[:2]
    center = (rows / 2, cols / 2)
    for x in range(cols):
        for y in range(rows):
            base[y, x] = 1 - exp(((-distance((y, x), center) ** 2) / (2 * (D0 ** 2))))
    return base

def idealFilterHP(D0,imgShape):
    base = np.ones(imgShape[:2])
    rows, cols = imgShape[:2]
    center = (rows/2,cols/2)
    for x in range(cols):
        for y in range(rows):
            if distance((y,x),center) < D0:
                base[y,x] = 0
    return base

# Import image
image = cv2.imread("C:/Users/TOBI/Documents/Belajar_Python/PCD_prak/p8/leaf-spot-disease-control-in-michigan.jpg")
# Change color space
kanvas_YUV = cv2.cvtColor(image, cv2.COLOR_BGR2YUV)
# kanvas_HSV = cv2.cvtColor(image, cv2.COLOR_BGR2HSV)
# kanvas_LAB = cv2.cvtColor(image, cv2.COLOR_BGR2Lab)

# # Split channel yang ada
# h,s,v_ = cv2.split(kanvas_HSV)
y,u,v = cv2.split(kanvas_YUV)
# l,a,b = cv2.split(kanvas_LAB)

# Buat file gambar dari channel yang sudah di-split
# cv2.imshow("./fix/Channel_v_yuv.png", v)
# cv2.imshow("./hsv/Channel_h.png", h)
# cv2.imshow("./hsv/Channel_s.png", s)
# cv2.imshow("./hsv/Channel_v.png", v_)
cv2.imshow("ch y", y)
cv2.imshow("ch u", u)
cv2.imshow("ch v", v)
# cv2.imshow("./lab/Channel_l.png", l)
# cv2.imshow("./lab/Channel_a.png", a)
# cv2.imshow("./lab/Channel_b.png", b)

# Calculate image in frequency domain at matplot
original = np.fft.fft2(v)
center = np.fft.fftshift(original)
# Radius of filter
radius = 17
# Gaussian High Pass Filter
GaussianHP = gaussianHP(radius, v.shape)

# Output after using GaussianHP
HighPassCenter = center * GaussianHP
HighPass = np.fft.ifftshift(HighPassCenter)
inverse_HighPass = np.fft.ifft2(HighPass)

# Create plotting
plt.figure(figsize=(12.8 * 1.5, 4.0 * 1.5), constrained_layout=False)
plt.subplot(231), plt.imshow(u, "gray"), plt.title("Gambar asli"), plt.xticks([]), plt.yticks([])
plt.subplot(232), plt.imshow(np.log(1 + np.abs(center)), "gray"), plt.title("Spectrum"), plt.xticks([]), plt.yticks([])
plt.subplot(233), plt.imshow(GaussianHP, "gray"), plt.title("Gaussian High Pass Filter"), plt.xticks([]), plt.yticks([])
plt.subplot(234), plt.imshow(np.log(1 + np.abs(HighPassCenter)), "gray"), plt.title(
    "Centered Spectrum GaussianHP"), plt.xticks([]), plt.yticks([])
plt.subplot(235), plt.imshow(np.log(1 + np.abs(HighPass)), "gray"), plt.title("Decentralize"), plt.xticks(
    []), plt.yticks([])
plt.subplot(236), plt.imshow(np.abs(inverse_HighPass), "gray"), plt.title("Gaussian High Pass"), plt.xticks(
    []), plt.yticks([])

# Show plot
plt.show()

cv2.waitKey(0)
cv2.destroyAllWindows()