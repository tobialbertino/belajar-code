#set directory
setwd("E:/Tugas 10")
#import library
library("OpenImageR")
library("jpeg")
library("matlib")
#import file
filenames <- list.files(pattern = "contoh.jpg", full.names = TRUE)
citra <- lapply(filenames, readJPEG)
#image menjadi matrix
matcitra <- as.matrix(citra[[1]])
image(matcitra,col=grey(seq(0, 1, length = 256)))
#hitung X'X
matx <- t(matcitra) %*% matcitra
#eigen vector & eigen value
eig <- eigen(matx)
eigval <- eig$values
eigvec <- eig$vectors
#sqrt eigval
eigvals <- c()
for(i in 1:length(eigval)){
  eigvals[i] <- sqrt(eigval[i])
}
#r = 5
#matrix l
matl <- diag(eigvals[1:5], 5, 5)
#matrix a
mata <- eigvec[,1:5]
#matrix u
matu <- c()
for(i in 1:5){
  matu <- cbind(matu, (1/eigvals[i])*matcitra %*% mata[,i])
}
#dekompresi
math5 <- matu %*% matl %*% t(mata)
image(math5,col=grey(seq(0, 1, length = 256)))
#r=25
#matrix l
matl <- diag(eigvals[1:25], 25, 25)
#matrix a
mata <- eigvec[,1:25]
#matrix u
matu <- c()
for(i in 1:25){
  matu <- cbind(matu, (1/eigvals[i])*matcitra %*% mata[,i])
}
#dekompresi
math25 <- matu %*% matl %*% t(mata)
image(math25,col=grey(seq(0, 1, length = 256)))
#r=50
#matrix l
matl <- diag(eigvals[1:50], 50, 50)
#matrix a
mata <- eigvec[,1:50]
#matrix u
matu <- c()
for(i in 1:50){
  matu <- cbind(matu, (1/eigvals[i])*matcitra %*% mata[,i])
}
#dekompresi
math50 <- matu %*% matl %*% t(mata)
image(math50,col=grey(seq(0, 1, length = 256)))
#r=150
#matrix l
matl <- diag(eigvals[1:150], 150, 150)
#matrix a
mata <- eigvec[,1:150]
#matrix u
matu <- c()
for(i in 1:150){
  matu <- cbind(matu, (1/eigvals[i])*matcitra %*% mata[,i])
}
#dekompresi
math150 <- matu %*% matl %*% t(mata)
image(math150,col=grey(seq(0, 1, length = 256)))
#r=200
#matrix l
matl <- diag(eigvals[1:200], 200, 200)
#matrix a
mata <- eigvec[,1:200]
#matrix u
matu <- c()
for(i in 1:200){
  matu <- cbind(matu, (1/eigvals[i])*matcitra %*% mata[,i])
}
#dekompresi
math200 <- matu %*% matl %*% t(mata)
image(math200,col=grey(seq(0, 1, length = 256)))