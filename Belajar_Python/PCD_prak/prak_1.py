# Program 1
# Program OpenCV sederhana untuk membaca dan menampilkan citra daun.
# Import package cv2 untuk opencv-python dan numpy
import numpy as np #untuk meringkas numpy menjadi np agar tidak terlalu panjang
import cv2
#Membaca file bernama daun.jpg
image = cv2.imread('daun.jpg')

#Menampilkan citra
cv2.imshow("Gambar", image)
#Mengambil nilai dimensi (panjang dan lebar) dan channel citra
row,col,ch = image.shape
#Membuat kanvas kosong
kanvas = np.zeros((row,col,3), np.uint8)
#Menyimpan nilai citra pada kanvas
for i in range (0,row):
    for j in range (0,col):
        kanvas[i,j]=image[i,j]


kanvas = np.zeros((row, col, 3), np.uint8)
for x in range(row):
    for y in range(col):
        b, g, r = image[x, y]
        kanvas.itemset((x, y, 0), b)
        kanvas.itemset((x, y, 1), g)
        kanvas.itemset((x, y, 2), r)

# NO 2 ubah ke grayscale-format[B, G, R]
grey = np.zeros((row, col), np.uint8)
for x in range(row):
    for y in range(col):
        grey[x, y] = np.clip(0.114 * image[x, y, 0] +
                            0.587 * image[x, y, 1] +
                            0.299 * image[x, y, 2], 0, 255)
        if grey[x, y] < 150:
            grey[x, y] = 255

# No 3 Transpose matrix
# display
cv2.imshow("Gambar hasil 1", kanvas)
cv2.imshow("Gambar hasil 2", grey)
cv2.waitKey(0)