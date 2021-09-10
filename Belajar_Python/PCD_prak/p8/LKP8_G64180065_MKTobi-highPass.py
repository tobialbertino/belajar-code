#coding:utf-8

import cv2
import numpy as np


def createHPFilter(shape, center, radius, lpType=2, n=2):
    rows, cols = shape[:2]
    r, c = np.mgrid[0:rows:1, 0:cols:1]
    c -= center[0]
    r -= center[1]
    d = np.power(c, 2.0) + np.power(r, 2.0)
    lpFilter_matrix = np.zeros(shape, np.float32)
    if lpType == 0:  # Ideal high pass filter
        lpFilter = np.copy(d)
        lpFilter[lpFilter < pow(radius, 2.0)] = 0
        lpFilter[lpFilter >= pow(radius, 2.0)] = 1
    elif lpType == 1: #Butterworth Highpass Filters 
        lpFilter = 1.0 - 1.0 / (1 + np.power(np.sqrt(d)/radius, 2*n))
    elif lpType == 2: # Gaussian Highpass Filter 
        lpFilter = 1.0 - np.exp(-d/(2*pow(radius, 2.0)))
    lpFilter_matrix[:, :, 0] = lpFilter
    lpFilter_matrix[:, :, 1] = lpFilter
    return lpFilter_matrix

def stdFftImage(img_gray, rows, cols):
    fimg = np.copy(img_gray)
    fimg = fimg.astype(np.float32)   #Notice the type conversion here
    # 1.Image matrix times(-1)^(r+c), Centralization
    for r in range(rows):
        for c in range(cols):
            if (r+c) % 2:
                fimg[r][c] = -1 * img_gray[r][c]
    img_fft = fftImage(fimg, rows, cols)
    return img_fft

def fftImage(img_gray, rows, cols):
    rPadded = cv2.getOptimalDFTSize(rows)
    cPadded = cv2.getOptimalDFTSize(cols)
    imgPadded = np.zeros((rPadded, cPadded), dtype=np.float32)
    imgPadded[:rows, :cols] = img_gray
    img_fft = cv2.dft(imgPadded, flags=cv2.DFT_COMPLEX_OUTPUT)
    return img_fft

def graySpectrum(fft_img):
    real = np.power(fft_img[:, :, 0], 2.0)
    imaginary = np.power(fft_img[:, :, 1], 2.0)
    amplitude = np.sqrt(real+imaginary)
    spectrum = np.log(amplitude+1.0)
    spectrum = cv2.normalize(spectrum, 0, 1, norm_type=cv2.NORM_MINMAX, dtype=cv2.CV_32F)
    spectrum *= 255
    return amplitude, spectrum

def nothing(args):
    pass

if __name__ == "__main__":
    img_file = r"C:/Users/TOBI/Documents/Belajar_Python/PCD_prak/p8/cameraman.png"
    # img_file = r"D:\data\receipt_rotate.jpg"
    img_gray = cv2.imread(img_file, 0)
    # 1.fast Fourier transform 
    rows, cols = img_gray.shape[:2]
    img_fft = stdFftImage(img_gray, rows, cols)
    amplitude, _ = graySpectrum(img_fft)
    minValue, maxValue, minLoc, maxLoc = cv2.minMaxLoc(amplitude)  # The maximum value of the spectrum after centralization is at the center of the image

    cv2.namedWindow("tracks")
    max_radius = np.sqrt(pow(rows, 2) + pow(cols, 2))
    cv2.createTrackbar("Radius", "tracks", 0, int(max_radius), nothing)
    cv2.createTrackbar("Filter type", "tracks", 0, 2, nothing)

    while True:
        # 2.Construction of high pass filter
        radius = cv2.getTrackbarPos("Radius", "tracks")
        lpType = cv2.getTrackbarPos("Filter type", "tracks")
        nrows, ncols = img_fft.shape[:2]
        # x, y = int(ncols / 2), int(nrows / 2)  # Notice here are the coordinates
        # ilpFilter = createHPFilter(img_fft.shape, (x, y), radius, lpType)
        ilpFilter = createHPFilter(img_fft.shape, maxLoc, radius, lpType)

        # 3.High pass filter
        img_filter = ilpFilter * img_fft

        _, gray_spectrum = graySpectrum(img_filter)  # Observe the change of the filter

        # 4. Inverse Fourier transform, and take the real part for cutting, And decentralize
        img_ift = cv2.dft(img_filter, flags=cv2.DFT_INVERSE + cv2.DFT_REAL_OUTPUT + cv2.DFT_SCALE)
        ori_img = np.copy(img_ift[:rows, :cols])
        for r in range(rows):
            for c in range(cols):
                if (r + c) % 2:
                    ori_img[r][c] = -1 * ori_img[r][c]
                # Truncate high and low values
                if ori_img[r][c] < 0:
                    ori_img[r][c] = 0
                if ori_img[r][c] > 255:
                    ori_img[r][c] = 255
        # ori_img[ori_img < 0] = 0
        # ori_img[ori_img > 255] = 255
        ori_img = ori_img.astype(np.uint8)

        cv2.imshow("img_gray", img_gray)
        cv2.imshow("ori_img", ori_img)
        cv2.imshow("gray_spectrum", gray_spectrum)
        key = cv2.waitKey(1)
        if key == 27:
            break
    cv2.destroyAllWindows()