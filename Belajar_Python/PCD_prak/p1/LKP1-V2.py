import numpy as np
import cv2
# image = cv2.imread('D:\\PCD\\horse.jpg', 1)
image = cv2.imread('daun.jpg')
# Mengambil nilai dimensi (panjang dan lebar) dan channel citra
row, col, ch = image.shape

# NO 1 Membuat kanvas kosong / Matrix untuk gambar RGB
kanvas = np.zeros((row, col, 3), np.uint8)

# NO 2 ubah ke grayscale-format[B, G, R]
def bgr2gray(bgr):
    b, g, r = bgr[:,:,0], bgr[:,:,1], bgr[:,:,2]
    gray = 0.114 * b + 0.587 * g + 0.299 * r
    return gray
grey_image = bgr2gray(image)
grey_image = grey_image.astype(np.uint8)
# bgr_weights = [0.114, 0.587, 0.299]
# grey_image = np.dot(image[:, :, :3], bgr_weights)

# gray = bgr2gray(image)
# grey = np.zeros((row, col), np.uint8)
# for x in range(row):
#     for y in range(col):
#         grey[x, y] = np.clip(grey_image[x, y, 0] +
#                             grey_image[x, y, 1] +
#                             grey_image[x, y, 2], 0, 255)
#         if grey[x, y] < 150:
#             grey[x, y] = 255

# No 3 Transpose matrix
kanvasT = np.zeros((col, row, 3), np.uint8)
for x in range(row):
    for y in range(col):
        kanvasT[y, x] = image[x, y]

print(type(grey_image))
print(grey_image[1,1])
# # display
# cv2.imshow("Gambar hasil 1", grey_image)
# cv2.imshow("Gambar hasil 2", kanvasT)
cv2.imshow("Gambar hasil 3", grey_image)
cv2.waitKey(0)

