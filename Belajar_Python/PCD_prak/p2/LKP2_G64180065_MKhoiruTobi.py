import numpy as np
import cv2
# Uncomment
# NO 1 ________________________________________________________________
# read image
img = cv2.imread('lenna.png')
# Mengambil nilai dimensi (panjang dan lebar) dan channel citra
row, col, ch = img.shape

# RGB -> HSV func/ch color
def bgr2hsv(b, g, r):
    b, g, r = b/255.0, g/255.0, r/255.0
    v = max(b, g, r)
    mn = min(b, g, r)
    df = v-mn
    if v != 0:
        s = (df/v)
    else:
        s = 0
    if v == r:
        h = (60 * ((g-b)/df) + 360) % 360
    elif v == g:
        h = (60 * ((b-r)/df) + 120) % 360
    elif v == b:
        h = (60 * ((r-g)/df) + 240) % 360
    elif ((r == g) == b):
        h = 0
    # output 8-bit color 
    v *= 255
    s *= 255
    h /= 2

    return h, s, v
# loop func 
def bgr2hsv_loop(img):
    row, col, ch = img.shape
    out = np.zeros((row, col, ch), dtype=np.float32)

    for i in range(row):
        for j in range(col):
            b, g, r = img[i, j]
            out[i, j] = bgr2hsv(b, g, r)

    return out

hsv_img = bgr2hsv_loop(img).astype(np.uint8)

# split 
hue, sat, val = cv2.split(hsv_img)
mean_hue = int(hue.mean())
mean_sat = int(sat.mean())
mean_val = int(val.mean())
# print(type(hue))

hue[hue < mean_hue] = 0
hue[hue >= mean_hue] = 255
sat[sat < mean_sat] = 0
sat[sat >= mean_sat] = 255
val[val < mean_val] = 0
val[val >= mean_val] = 255

# display
# cv2.imshow("Gambar hsv real", test0)
cv2.imshow("Gambar hsv", hsv_img)
cv2.imshow("Gambar 1", hue)
cv2.imshow("Gambar 2", sat)
cv2.imshow("Gambar 3", val)
cv2.waitKey(0)

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