import numpy as np
import matplotlib.pyplot as plt
import cv2
import pywt
import pywt.data

# Load image
image = cv2.imread("C:/Users/TOBI/Documents/Belajar_Python/PCD_prak/p10/leaf-spot-disease-control-in-michigan.jpg")
kanvas_YUV = cv2.cvtColor(image, cv2.COLOR_BGR2YUV)
y,u,v = cv2.split(kanvas_YUV)
img = v
img_shape = img.shape

# Otsu's thresholding
# graytemp = cv2.cvtColor(original, cv2.COLOR_BGR2GRAY)
# tresh,bw = cv2.threshold(graytemp,0,255,cv2.THRESH_BINARY+cv2.THRESH_OTSU)
bw = img

cv2.imshow('hasil',bw)

# Wavelet transform of image, and plot approximation and details
titles = ['Approximation/LL', ' Horizontal detail/HL',
          'Vertical detail/LH', 'Diagonal detail/HH']
coeffs2 = pywt.dwt2(bw,'sym2')
LL, (LH, HL, HH) = coeffs2
result = LL.flatten()
result2 = LH.flatten()
result3 = HL.flatten()
result4 = HH.flatten()

fig = plt.figure(figsize=(12,3))
for i, a in enumerate([LL, LH, HL, HH]):
    ax = fig.add_subplot(1, 4, i + 1)
    ax.imshow(a, interpolation="nearest", cmap=plt.cm.gray)
    ax.set_title(titles[i], fontsize=10)
    ax.set_xticks([])
    ax.set_yticks([])

fig, ax = plt.subplots(1,4,figsize=(30, 5))
ax[0].plot(result)
ax[1].plot(result2)
ax[2].plot(result3)
ax[3].plot(result4)

fig.tight_layout()
plt.show()


titles = ['Approximation/LL', ' Horizontal detail/HL',
            'Vertical detail/LH', 'Diagonal detail/HH']
coeffs2 = pywt.dwt2(inv, 'sym2')
LL, (LH, HL, HH) = coeffs2
result = LL.flatten()
result2 = LH.flatten()
result3 = HL.flatten()
result4 = HH.flatten()

fig = plt.figure(figsize=(12,3))
for i, a in enumerate([LL, LH, HL, HH]):
    ax = fig.add_subplot(1, 4, i + 1)
    ax.imshow(a, interpolation="nearest", cmap=plt.cm.gray)
    ax.set_title(titles[i], fontsize=10)
    ax.set_xticks([])
    ax.set_yticks([])

fig, ax = plt.subplots(1, 4, figsize=(30, 5))
ax[0].plot(result)
ax[1].plot(result2)
ax[2].plot(result3)
ax[3].plot(result4)

fig.tight_layout()
plt.show()