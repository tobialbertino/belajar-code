import cv2
# Load a color image in grayscale
img1 = cv2.imread('image.jpg', 0)
img2 = cv2.imread('image.jpg', 0)
image = cv2.imread('image.jpg', 0)

# cv2.imread(filename) 
# cv2.cvtColor(input_image, flag) 
# cv2.imwrite(filename, image)

# cv2.threshold(source, thresholdValue, maxVal, thresholdingTechnique)

# Addition 
addition = cv2.add(img1, 100)
addition = cv2.add(img1, img2
# subtraction 
# substraction = cv2.subtract(img1, 100)
# substraction = cv2.subtract(img1, img2)

# Multiply = cv2.multiply(img1, 2)
# Divide = cv2.divide(img1,2)

import cv2
# buka citra
img = cv2.imread('image.jpg')
# assign row col
row, col, ch = img.shape
# buat salinan dari citra yang akan dijadikan grayscale
img_gray = img.copy()
# ubah color space dari img_gray menjadi grayscale
img_gray = cv2.cvtColor(img_gray, cv2.COLOR_BGR2GRAY)
# simpan citra ke sebuah file
cv2.imwrite('image_grayscale.jpg', img_gray)



import cv2
# buka citra
img = cv2.imread('image.jpg')
# assign row col
row, col, ch = img.shape
# buat salinan dari citra yang akan dijadikan grayscale
img_gray = img.copy()
# ubah color space dari img_gray menjadi grayscale
img_gray = cv2.cvtColor(img_gray, cv2.COLOR_BGR2GRAY)
# fungsi threshold. Semua pixel yang bernilai di atas 100
# akan diubah menjadi 255, selainnya menjadi 0.
ret, thresh = cv2.threshold(img_gray, 100, 255, cv2.THRESH_BINARY)
# tampilkan citra hasil
cv2.imshow('threshold', thresh)
cv2.waitKey(0)