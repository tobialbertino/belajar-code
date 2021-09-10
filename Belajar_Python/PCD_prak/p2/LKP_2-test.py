import numpy as np
import cv2
# Uncomment
# NO 2 ________________________________________________________________
# read image
img_lenna = cv2.imread('lenna.png')
img_equGray = cv2.imread('equ_gray.png')

def bgr2gray(img): # np.dot
    b, g, r = img[:,:,0], img[:,:,1], img[:,:,2]
    gray = 0.114 * b + 0.587 * g + 0.299 * r
    return gray

gray_lenna = bgr2gray(img_lenna)
gray_equ = bgr2gray(img_equGray)

def imageDiff(img1, img2):
    mean_img1 = int(img1.mean())
    mean_img2 = int(img2.mean())

    img1 = img1.astype(np.float32)
    img2 = img2.astype(np.float32)

    img1[img1 < mean_img1] *= 0.5
    img1[img1 >= mean_img1] *= 2
    img1 = img1.astype(np.int32)
    img2[img2 < mean_img2] *= 0.5
    img2[img2 >= mean_img2] *= 2
    img2 = img2.astype(np.int32)

    out = img1 - img2
    out[out < 0] = 0
    print(mean_img1)
    print(mean_img2)

    return out

out = imageDiff(gray_lenna, gray_equ)
out = out.astype(np.uint8)

print(type(gray_lenna))

print(img_lenna.shape)
print(img_equGray.shape)
print(gray_lenna.shape)
print(gray_equ.shape)
# display
cv2.imshow("Gambar diff", out)
cv2.waitKey(0)
