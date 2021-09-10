import numpy as np
import cv2
from matplotlib import pyplot as plt
import pywt
from pywt._doc_utils import wavedec2_keys, draw_2d_wp_basis

# Load image
img = cv2.imread("C:/Users/TOBI/Documents/Belajar_Python/PCD_prak/p9/k_cameraman.jpg", 0)
img_shape = img.shape

max_lev = 3  # how many levels of decomposition to draw
label_levels = 3  # how many levels to explicitly label on the plots

def dwtwithLevel(image, shape):
    fig, axes = plt.subplots(2, 4, figsize=[14, 8])
    for level in range(0, max_lev + 1):
        if level == 0:
            # show the original image before decomposition
            axes[0, 0].set_axis_off()
            axes[1, 0].imshow(image, cmap=plt.cm.gray)
            axes[1, 0].set_title('Image')
            axes[1, 0].set_axis_off()
            continue

        # plot subband boundaries of a standard DWT basis
        draw_2d_wp_basis(shape, wavedec2_keys(level), ax=axes[0, level], 
        label_levels=label_levels)
        axes[0, level].set_title('{} level\ndecomposition'.format(level))

        # compute the 2D DWT
        coeffs = pywt.wavedec2(image, 'haar', mode='periodization', level=level)

        # normalize each coefficient in array independently for better result
        coeffs[0] /= np.abs(coeffs[0]).max()
        for detail_level in range(level):
            coeffs[detail_level + 1] = [d / np.abs(d).max() for d in coeffs[detail_level + 1]]
        # display normalized coefficients
        arr, slices = pywt.coeffs_to_array(coeffs)
        axes[1, level].imshow(arr, cmap=plt.cm.gray)
        axes[1, level].set_title('Coefficients\n({} level)'.format(level))
        axes[1, level].set_axis_off()

    plt.tight_layout()
    plt.show()

dwtwithLevel(img, img_shape)

cv2.waitKey()
cv2.destroyAllWindows()
