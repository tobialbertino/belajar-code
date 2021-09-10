import numpy as np 
import cv2

# Fungsi untuk menambah padding 1 level
def addPadding(img):
    row, col = img.shape
    out = np.zeros((row+2, col+2))
    for i in range(row):
        for j in range(col):
            out[i+1, j+1] = img[i, j]
    return out

# Fungsi konvolusi dengan Msk/Filter tertentu 
def customConvolution(img, mask):
    row, col = img.shape
    mRow, mCol = mask.shape
    # tambahkan padding 1 level 
    padded_img = addPadding(img)
    out = np.zeros((row+2, col+2), dtype=np.uint8)
    for i in range(1, row+1):
        for j in range(1, col+1):
            imgSum = 0
            for a in range(int(-mRow/2), mRow-int(mRow/2)):
                for b in range(int(-mCol/2), mCol-int(mCol/2)):
                    if ((i+a >= 0) and (j+b >= 0)):
                        imgSum += padded_img[i+a, j+b] * mask[int(a+mRow/2), int(b+mCol/2)]
                        # maskSum += mask[int(a+mRow/2), int(b+mCol/2)]
            out[i, j] = imgSum
    return out

# baca gambar dalam format Grayscale
img = cv2.imread('C:/Users/TOBI/Documents/Belajar_Python/PCD_prak/p4/lenna.png', 0)

# filter LowPassFilter 
lpf = np.array(([0, 1/8, 0],
                [1/8, 4/8, 1/8],
                [0, 1/8, 0]))
# filter High pass filter
hpf = np.array(([-1/9, -1/9, -1/9],
                [-1/9, 8/9, -1/9],
                [-1/9, -1/9, -1/9]))
# filter Directional filter
df = np.array(([-1, 0, 1],
                [-1, 0, 1],
                [-1, 0, 1]))

hasil_lpf = customConvolution(img, lpf)
hasil_hpf = customConvolution(img, hpf)
hasil_df  = customConvolution(img, df)

cv2.imshow('Original image', img)
cv2.imshow('LPF', hasil_lpf)
cv2.imshow('HPF', hasil_hpf)
cv2.imshow('DF', hasil_df)

# cv2.imwrite("result-gray.png", img)
# cv2.imwrite("result-LPF.png", hasil_lpf)
# cv2.imwrite("result-HPF.png", hasil_hpf)
# cv2.imwrite("result-DF.png", hasil_df)
cv2.waitKey(0)

print(lpf.shape)