import cv2 as cv
import numpy as np

#baca gambar
img= cv.imread('daun.jpg')

#simpan citra
row,col,ch= img.shape

#simpan nilai tiap pixel ke variabel knv
knv= np.zeros((row,col,3), np.uint8)
for i in range (0,row):
	for j in range (0,col):
		knv[i,j]=img[i,j]
#cv.imshow('nomer1', knv)
#cv.waitKey(0)

#ubah gambar knv ke grayscale dan naikkan jika nilai dibawah 150 ke 255
for i in range (0,row):
	for j in range (0,col):
		blue, green, red= img[i,j]
		gray = (red * 0.299 + green * 0.587 + blue * 0.114)
		if(gray<150): gray= 255
		knv.itemset((i, j, 0), gray)
		knv.itemset((i, j, 1), gray)
		knv.itemset((i, j, 2), gray)
cv.imshow('nomer2', knv)
#cv.waitKey(0)

#buat matrix transpose dari img
img_transpose= np.zeros((col,row,3), np.uint8)
for i in range (0,row):
	for j in range (0,col):
		img_transpose[j,i]=img[i,j]

#resize sedikit agar gambar terlihat full di layar
resize_w= int(img_transpose.shape[1]*0.5)
resize_h= int(img_transpose.shape[0]*0.5)
dim=(resize_w,resize_h)
img_transpose= cv.resize(img_transpose, dim, interpolation = cv.INTER_AREA)
cv.imshow('nomer3', img_transpose)
cv.waitKey(0)


