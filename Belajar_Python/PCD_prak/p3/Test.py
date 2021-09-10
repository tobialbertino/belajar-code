import numpy as np 
import matplotlib.pyplot as plt 
import cv2

# fungsi histogram  
# histogram untuk plot array 1D 
def histogram2(name, hist):
    xbar = np.array([0, 1, 2, 3, 4, 5, 6, 7])
    plt.figure(name)
    plt.title(name)
    plt.xlabel('Grey level')
    plt.xticks( 
        [0, 1, 2, 3, 4, 5, 6, 7],
        ['0', '1/7', '2/7', '3/7', '4/7', '5/7', '6/7', '1'])
    plt.bar(xbar, hist)
    # plt.savefig('{}.png'.format(name.lower()))
    return plt.show()
def histogram3(name, hist):
    xbar = np.array([0, 1, 2, 3, 4, 5, 6, 7])
    plt.figure(name)
    plt.title(name)
    plt.xlabel('Grey level before')
    plt.xticks( 
        [0, 1, 2, 3, 4, 5, 6, 7],
        ['0', '1/7', '2/7', '3/7', '4/7', '5/7', '6/7', '1'])
    plt.ylabel('Grey level after')
    plt.yticks( 
        [0, 1, 2, 3, 4, 5, 6, 7],
        ['0', '1/7', '2/7', '3/7', '4/7', '5/7', '6/7', '1'])
    plt.bar(xbar, hist)
    # plt.savefig('{}.png'.format(name.lower()))
    return plt.show()

def histogram_komulatif(prob):
    hist = np.zeros(8)
    total = 0
    for i in range(8):
        total += prob[i]
        hist[i] = total
    return hist

total = 4096
# jumlah kemunculan 
muncul = np.array([400, 700, 800, 900, 500, 400, 196, 200], dtype=np.float)
hist1 = histogram2("jumlah muncul", muncul)
prob = muncul / total
hist2 = histogram2("normalisasi histogram", prob)
komulatif = histogram_komulatif(prob)
hist3 = histogram2("histogram komulatif", komulatif)

equalized = komulatif * 7
hist4 = histogram3("histogram equalization", equalized)

out = np.zeros(8)
final = np.zeros(8)
for i in range(8):
    out[i] = equalized[i]
out = out.astype(np.int)
print(out)
# [0 1 3 4 5 6 6 7]
final[0] += muncul[0]
final[1] += muncul[1]
final[3] += muncul[2]
final[4] += muncul[3]
final[5] += muncul[4]
final[6] += muncul[5]
final[6] += muncul[6]
final[7] += muncul[7]

hist5 = histogram2("Final", final)