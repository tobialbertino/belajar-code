#LKP6 -- calculator
i1= c(1,1,1,0)
i2= c(1,0,1,1)
i3= c(0,1,1,0)
i4= c(0,0,1,1)
w1= c(0.2,0.6,0.8,0.9)
w2= c(0.8,0.4,0.7,0.3)

#learning rate
n= function(t){
  if(t<=4){
    x= 0.6
  }
  if(t>=5 & t<=8){
    x= 0.5*0.6
  }
  return(x)
}

#rumus distance menggunakan euclidean
d= function(p,q){
  sum((p-q)^2)
}

#rumus update bobot
w_update<- function(i, w, n){
  w= w+n*(i-w)
  return(w)
}

#EPOCH=1 ----------------------------------------
#percobaan data train i1
#cari jarak terpendek antara i1 dan (w1 atau w2)
d(i1, w1)
d(i1, w2)
#w2 lebih dekat dengan i1, maka update bobot w2
#t= 1, maka ambil learning rate n(1)
alpha= n(1)
w2= w_update(i1, w2, alpha)
#tampilkan w1 dan w2
w1
w2

#percobaan data tran i2
#cari jarak terpendek antara i1 dan (w1 atau w2)
d(i2, w1)
d(i2, w2)
#w1 lebih dekat dengan i2, update bobot w1
#t= 2, ambil learning rate n(2)
alpha= n(2)
w1= w_update(i2, w1, alpha)
#tampilkan w1 dan w2
w1
w2

#percobaan data train i3
#cari jarak terpendek antara i3 dan (w1 atau w2)
d(i3, w1)
d(i3, w2)
#w2 lebih dekat dengan i3, maka update bobot w2
#t= 3, maka ambil learning rate n(3)
alpha= n(3)
w2= w_update(i3, w2, alpha)
#tampilkan w1 dan w2
w1
w2

#percobaan data train i4
#cari jarak terpendek antara i4 dan (w1 atau w2)
d(i4, w1)
d(i4, w2)
#w1 lebih dekat dengan i4, maka update bobot w1
#t= 4, maka ambil learning rate n(4)
alpha= n(4)
w1= w_update(i4, w1, alpha)
#tampilkan w1 dan w2
w1
w2

#EPOCH= 2 ------------------------------------
#percobaan data train i1
#cari jarak terpendek antara i1 dan (w1 atau w2)
d(i1, w1)
d(i1, w2)
#w2 lebih dekat dengan i1, maka update bobot w2
#t= 5, maka ambil learning rate n(5)
alpha= n(5)
w2= w_update(i1, w2, alpha)
#tampilkan w1 dan w2
w1
w2

#percobaan data tran i2
#cari jarak terpendek antara i1 dan (w1 atau w2)
d(i2, w1)
d(i2, w2)
#w1 lebih dekat dengan i2, update bobot w1
#t= 6, ambil learning rate n(6)
alpha= n(6)
w1= w_update(i2, w1, alpha)
#tampilkan w1 dan w2
w1
w2

#percobaan data train i3
#cari jarak terpendek antara i3 dan (w1 atau w2)
d(i3, w1)
d(i3, w2)
#w2 lebih dekat dengan i3, maka update bobot w2
#t= 7, maka ambil learning rate n(7)
alpha= n(7)
w2= w_update(i3, w2, alpha)
#tampilkan w1 dan w2
w1
w2

#percobaan data train i4
#cari jarak terpendek antara i4 dan (w1 atau w2)
d(i4, w1)
d(i4, w2)
#w1 lebih dekat dengan i4, maka update bobot w1
#t= 8, maka ambil learning rate n(8)
alpha= n(8)
w1= w_update(i4, w1, alpha)
#tampilkan w1 dan w2
w1
w2
