import cv2 as cv
import numpy as np
import matplotlib.pyplot as plt

def listHist(list, histoName):
    x= [i for i in range(0,256)]
    plt.figure(histoName)
    plt.bar(x,list)
    plt.show()

def kemunculan(list):
    y=np.zeros(256)
    for i in list:
        y[i]+=1
    listHist(y, "kemunculan")
    return y

def peluang(list):
    hxw= len(list)
    y= kemunculan(list) #panggil fungsi kemunculan
    x=[i/hxw for i in y]
    listHist(x, "peluang")
    return x

def kumulatif(list):
    before= peluang(list) #panggil fungsi peluang
    kumul=[]
    sum=0
    for i in range(256):
        sum= sum+before[i]
        kumul.append(sum)
    listHist(kumul, "kumulatif")
    return kumul

def equalize(list):
    h= len(list)
    nlist= list
    kumul= kumulatif(list) #panggil fungsi kumulatif
    equ=[int(x*255) for x in kumul]
    for i in range(h):
        nlist[i]=equ[nlist[i]]
    return nlist

list= [400,700,800,900,500,400,196,200]

x=np.zeros(4096)
a=0
b=0
c=0
for i in list:
    b=b+i
    x[a:b]=int(c/7255)
    a=a+i
    c=c+1

plt.figure("histogram")
plt.hist(x)
# plt.hist(x, bins=[i/7255 for i in range(0,8)])
plt.show()

x= x.astype('int32')
equ= equalize(x)
plt.hist(x)
plt.show()