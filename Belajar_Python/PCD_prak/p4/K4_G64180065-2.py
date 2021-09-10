import cv2 as cv
import numpy as np
import os

#ubah working directory
os.chdir('<your directory>')

#baca gambar
src = cv.imread('source.jpg')
src_gs = cv.imread('source.jpg',0)
#baca objek yang ingin dicari pada gambar
find = cv.imread('find.jpg', 0)
find2 = cv.imread('find2.jpg', 0)
find3 = cv.imread('find3.jpg', 0)
find4 = cv.imread('find4gg.jpg', 0)

hs, ws= src_gs.shape
hf, wf= find.shape

#pilih salah satu----------------
matching = cv.matchTemplate(src_gs, find, cv.TM_SQDIFF_NORMED) #metode CCOEFF_NORMED
#matching = cv.matchTemplate(src_gs, find, cv.TM_CCOEFF_NORMED) #metode CCOEFF_NORMED
#--------------------------------

min_val, max_val, min_loc, max_loc = cv.minMaxLoc(matching)
print(min_val, max_val, min_loc, max_loc)

#pilih salah satu, sesuaikan dengan metode yang dipilih ----
top_left= min_loc #untuk SQDIFF
#top_left= max_loc #untuk CCOEFF
#-----------------------------------------------------------

#fungsi untuk memberi tanda dengan kotak warna merah
#pada objek yang dipilih
bottom_right = (top_left[0] + wf, top_left[1] + hf)
cv.rectangle(src, top_left, bottom_right, (0, 0, 255), 2) 

#multiple object detection (optional)-----------
hf, wf= find2.shape
matching = cv.matchTemplate(src_gs, find2, cv.TM_SQDIFF_NORMED)
#matching = cv.matchTemplate(src_gs, find, cv.TM_CCOEFF_NORMED)
min_val, max_val, min_loc, max_loc = cv.minMaxLoc(matching)
top_left= min_loc #untuk SQDIFF
#top_left= max_loc #untuk CCOEFF
bottom_right = (top_left[0] + wf, top_left[1] + hf)
cv.rectangle(src, top_left, bottom_right, (0, 0, 255), 2)

hf, wf= find3.shape
matching = cv.matchTemplate(src_gs, find3, cv.TM_SQDIFF_NORMED)
#matching = cv.matchTemplate(src_gs, find, cv.TM_CCOEFF_NORMED)
min_val, max_val, min_loc, max_loc = cv.minMaxLoc(matching)
top_left= min_loc #untuk SQDIFF
#top_left= max_loc #untuk CCOEFF
bottom_right = (top_left[0] + wf, top_left[1] + hf)
cv.rectangle(src, top_left, bottom_right, (0, 0, 255), 2)

hf, wf= find4.shape
matching = cv.matchTemplate(src_gs, find3, cv.TM_SQDIFF_NORMED)
#matching = cv.matchTemplate(src_gs, find, cv.TM_CCOEFF_NORMED)
min_val, max_val, min_loc, max_loc = cv.minMaxLoc(matching)
top_left= min_loc #untuk SQDIFF
#top_left= max_loc #untuk CCOEFF
bottom_right = (top_left[0] + wf, top_left[1] + hf)
cv.rectangle(src, top_left, bottom_right, (0, 0, 255), 2)
#-----------------------------------------

cv.imshow("Detected!", matching) #last matching convoo
cv.imshow("ori!", src)
cv.waitKey()