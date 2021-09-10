import numpy as np
import cv2
# image = cv2.imread('D:\\PCD\\horse.jpg', 1)
image = cv2.imread('daun.jpg')
# Mengambil nilai dimensi (panjang dan lebar) dan channel citra
row, col, ch = image.shape

# NO 1 Membuat kanvas kosong / Matrix untuk gambar RGB
kanvas = np.zeros((row, col, 3), np.uint8)

# NO 2 ubah ke grayscale-format[B, G, R]
bgr_weights = [0.114, 0.587, 0.299]
# grey_image = np.dot(image[:, :, :3], bgr_weights)
def bgr2gray(bgr): # np.dot
    b, g, r = bgr[:,:,0], bgr[:,:,1], bgr[:,:,2]
    gray = 0.114 * b + 0.587 * g + 0.299 * r
    return gray

grey_image = bgr2gray(image)
grey_image = grey_image.astype(np.uint8) # convert -> unsigned int 8bit
# for x in range(row):
#     for y in range(col):
#         if grey_image[x, y] < 150:
#             grey_image[x, y] = 255
grey_image[grey_image < 150] = 255


# No 3 Transpose matrix
kanvasT = np.zeros((col, row, 3), np.uint8)
for x in range(row):
    for y in range(col):
        kanvasT[y, x] = image[x, y]

# display
cv2.imshow("Gambar hasil 2", grey_image)
cv2.imshow("Gambar hasil 3", kanvasT)
cv2.waitKey(0)
# print(image[1, 1, :3])
# print(bgr_weights)