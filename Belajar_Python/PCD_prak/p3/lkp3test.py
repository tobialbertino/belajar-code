import cv2
import numpy as np
import matplotlib.pyplot as plt

img = cv2.imread('C:/Users/TOBI/Documents/Belajar_Python/PCD_prak/p3/car.png')

def img_to_hist(name, image):
    plt.figure(name)
    plt.title(name)
    plt.hist(image.ravel(), 256, [0,256])
    # plt.savefig('{}.png'.format(name.lower()))
    return plt.show()

def list_to_hist(name, list):
    bin = [i for i in range(0, 256)]
    plt.figure(name)
    plt.title(name)
    plt.bar(bin, list)
    # plt.savefig('{}.png'.format(name.lower()))
    return plt.show()

def contrastStretching(image):
    row, col = image.shape
    canvas = np.zeros((row, col, 1), np.uint8)
    fmin = min(image.ravel())
    fmax = max(image.ravel())
    for i in range(0, row):
        for j in range(0, col):
            canvas[i, j] = ((image[i,j] - fmin)/(fmax-fmin)) * 255
    return canvas

def jmlKemunculan(image):
    row, col = image.shape
    kemunculan = [0]*256
    for i in range(0, row):
        for j in range(0, col):
            kemunculan[image[i, j]] += 1
    return kemunculan

def normalize(kemunculan, image):
    row, col = image.shape
    probability = [0]*256
    for i in range(0, 256):
        probability[i] = kemunculan[i] / (row * col)
    return probability

def kumulatifSum(normalisasi):
    kumulatif = [0]*256
    sum = 0
    for i in range(256):
        sum += normalisasi[i]
        kumulatif[i] = sum
    return kumulatif

def equalized(kumulatif, image):
    row, col = image.shape
    for i in range(0, 256):
        kumulatif[i] = kumulatif[i] * 255
    for i in range(row):
        for j in range(col):
            image[i, j] = kumulatif[image[i, j]]
    return image

def histogramEqualization(image):
    kemunculan = jmlKemunculan(image)
    normalisasi = normalize(kemunculan, image)
    kumulatif = kumulatifSum(normalisasi)
    ekualisasi = equalized(kumulatif, image)
    return normalisasi, kumulatif, ekualisasi

def bgr2gray(img): 
    b, g, r = img[:,:,0], img[:,:,1], img[:,:,2]
    gray = 0.114 * b + 0.587 * g + 0.299 * r
    return gray

gray_img = bgr2gray(img)

normalisasi, kumulatif, ekualisasi = histogramEqualization(gray_img)



cv2.imshow("Hasil histogram equalization", ekualisasi)



cv2.waitKey(0)