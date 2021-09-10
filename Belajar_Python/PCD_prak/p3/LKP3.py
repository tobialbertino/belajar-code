import numpy as np 
import matplotlib.pyplot as plt 
import cv2

# fungsi histogram  
def histogram(name, img):
    # jumlah bin = 256 
    plt.figure(name)
    plt.title(name)
    plt.hist(img.ravel(), 256, [0, 256])
    # plt.savefig('{}.png'.format(name.lower()))
    return plt.show()
# histogram untuk plot array 1D 
def histogram2(name, hist):
    bin = [i for i in range(256)]
    plt.figure(name)
    plt.title(name)
    plt.bar(bin, hist)
    # plt.savefig('{}.png'.format(name.lower()))
    return plt.show()

# fungsi convert grayscale dengan perkalian matriks #np.dot
def bgr2gray(img): 
    b, g, r = img[:,:,0], img[:,:,1], img[:,:,2]
    gray = 0.114 * b + 0.587 * g + 0.299 * r
    return gray

# fungsi untuk Contrast Stretching img 
def contrastStretching(img):
    row, col = img.shape
    out = np.zeros((row, col), dtype=np.float32)
    fmax = img.max()
    fmin = img.min()
    for i in range(row):
        for j in range(col):
            out[i, j] = (img[i, j] - fmin) / (fmax - fmin) * 255
    return out

# Fungsi" untuk melakukan histogram equalization 
# hit jumlah kemunculan tiap nilai pixel 
def jmlh_kemunculan(img):
    muncul = np.zeros((256), np.float32)
    row, col = img.shape
    for i in range(row):
        for j in range(col):
            muncul[img[i, j]] +=1
    return muncul
# normalisasi histogram 
def normalizedProb(muncul, img):
    prob = np.zeros((256))
    row, col = img.shape
    total = row * col
    for i in range(256):
        prob[i] = muncul[i] / total
    return prob
# hit histogram komulatif 
def histogram_komulatif(prob):
    hist = np.zeros(256)
    total = 0
    for i in range(256):
        total += prob[i]
        hist[i] = total
    return hist
# equalized, kali dengan 255
def equalized(hist, img):
    row, col = img.shape
    out = np.zeros((row, col), dtype=np.uint8)
    equalizer = hist * 255
    equalizer = equalizer.astype(np.int)
    for i in range(row):
        for j in range(col):
            out[i, j] = equalizer[img[i, j]]
    return out
# Lakukan histogram equalization
def  histogramEqualization(img):
    jumlah = jmlh_kemunculan(img)
    normalisasi = normalizedProb(jumlah, img)
    komulatif = histogram_komulatif(normalisasi)
    img_equalized = equalized(komulatif, img)
    
    return normalisasi, komulatif, img_equalized

# read image
img = cv2.imread('C:/Users/TOBI/Documents/Belajar_Python/PCD_prak/p3/car.png')
# convert grayscale 
img_gray = bgr2gray(img)
img_gray = img_gray.astype(np.uint8)

# contrast Stretching 
img_contrast = contrastStretching(img_gray)
img_contrast = img_contrast.astype(np.uint8)
# histogram equalization 
norm, kom, img_equalized =  histogramEqualization(img_gray)

# plot Histogram contrast Stretching
Himg_gray = histogram("gambar grayscale", img_gray)
Himg_contrast = histogram("hasil Contrast Stretching", img_contrast)
# plot Histogram histogram Equalization
Hnorm = histogram2('normalisasi', norm)
Hkomulatif = histogram2('komulatif', kom)
Himg_histEqualiz = histogram("hasil \nhistogram equalization", img_equalized)

print(img.shape)
print(img_gray.shape)
print(img_contrast.shape)
# display
cv2.imshow("Gambar grayscale", img_gray) 
cv2.imshow("Hasil contrast streching", img_contrast) 
cv2.imshow("Hasil histogram equalization", img_equalized)

# cv2.imwrite('melon_grayscale.png', img_gray)
# cv2.imwrite('melon_contrast strech.png', img_contrast)
# cv2.imwrite('melon_histogram equalization.png', img_equalized)
cv2.waitKey(0)
cv2.destroyAllWindows()