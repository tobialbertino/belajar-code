import cv2 as cv
import numpy as np

#Fungsi konvolusi
def customConvolution(image, mask):
	ih, iw, ch= image.shape
	mh, mw= mask.shape
	for i in ih:
		for j in iw:
			imageSum= 0
			maskSum= 0
			for a in range(int(-mh/2),int(mh-mh/2)):
				for b in range(int(-mw/2),int(mw-mw/2)):
					if i+a >= 0 and j+b >= 0:
						imageSum+= image[i+a,j+b]*mask[a+mh/2,b+mw/2]
						maskSum+= mask[a+mh/2,b+mw/2]

#fungsi konvolusi  citra dengan memasukkan
#image yang ingin diubah dan filter yang diinginkan
def citrakeun(image, kernel):
	#buat kanvas baru untuk menyimpan nilai
	#gambar yang sudah dicitrakan
	knv= image.copy()
	#tambahkan padding pada image
	image= np.pad(image, 1, mode='constant')
	#ambil nilai height dan weight dari image
	#yang sudah ditambahkan padding
	h, w= image.shape
	for i in range(1,h-1):
		for j in range(1,w-1):
			#masukkan hasil konvolusi kedalam kanvas
			knv[i-1,j-1]= (kernel[0,0]*image[i-1,j-1]+kernel[0,1]*image[i-1,j]+kernel[0,2]*image[i-1,j+1]+
				kernel[1,0]*image[i,j-1]+kernel[1,1]*image[i,j]+kernel[1,2]*image[i,j+1]+
				kernel[2,0]*image[i+1,j-1]+kernel[2,1]*image[i+1,j]+kernel[2,2]*image[i+1,j+1])
	return knv

#membaca gambar lenna.png
img= cv.imread('C:/Users/TOBI/Documents/Belajar_Python/PCD_prak/p4/lenna.png', 0)

#buat kernel filter low pass, high pass dan directional
lowpass_f= np.array([[0, 1/8, 0],[1/8, 4/8, 1/8],[0, 1/8, 0]])
highpass_f= np.array([[-1/9, -1/9, -1/9],[-1/9, 8/9, -1/9],[-1/9, -1/9, -1/9]])
directional_f= np.array([[-1, 0, 1],[-1, 0, 1],[-1, 0, 1]])

#lakukan konvolusi dengan kernel yang ada
lowpass_= citrakeun(img, lowpass_f)
highpass_= citrakeun(img, highpass_f)
directional_= citrakeun(img, directional_f)

#tampilkan gambar asli
cv.imshow('original', img)

#tampilkan gambar setelah dilakukan konvolusi
cv.imshow('lowpass', lowpass_)
cv.imshow('highpass', highpass_)
cv.imshow('directional', directional_)
cv.waitKey(0)