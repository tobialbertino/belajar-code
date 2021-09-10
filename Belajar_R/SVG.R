## import library
library("matrixcalc")

### set directory
setwd("C:/Users/TOBI/Downloads/Metode Kuantitatif")

## read data
dt <- read.csv("P9 data.csv")

## kasih nama barisnya
rname <- sprintf("G%d", seq(1:18))
rownames(dt) <- rname
dt

## ngurangin matriks awal sama rataannya
rataan <- c()
for(i in 1:nrow(dt)){
  rataan <- append(rataan, mean(dt[,i]))
}
for(i in 1:nrow(dt)){
  for(j in 1:ncol(dt)){
    dt[i,j] = dt[i,j] - rataan[j]
  }
}
dt

## bikin matriks C = X'X
C <- t(as.matrix(dt)) %*% as.matrix(dt)
C

## cari nilai eigen
ev <- eigen(C)
eigval <- ev$values
eigvec <- ev$vectors
eigval
eigvec

## hitung proporsi per vector eigen
sumEigVal <- sum(eigval)
prop = c()
for(i in 1:length(eigval)){
  prop = cbind(prop, eigval[i]/sumEigVal)
}
colnames(prop) <- sprintf("F%d", seq(1:9))
prop
barplot(prop)
cat("total proporsi yang ditangkap dari 2 eigen value :", sum(prop[1:2])*100)

## matriks L
L <- matrix(c(sqrt(eigval[1]), 0, 0, sqrt(eigval[2])), nrow = 2, ncol = 2)
L

## ambil 2 matriks dgn eigval terbesar (matriks A)
A <- eigvec[,1:2]
colnames(A) <- c("a1", "a2")
A

## matriks U
U <- c()
for(i in 1:2){
  U <- cbind(U, (1/L[i,i])*as.matrix(dt) %*% as.matrix(eigvec[,i]))
}
U

## matrix G
G <- sqrt(nrow(U)-1)*U
colnames(G) <- c("dim1", "dim2")
G

## matriks H
H <- t(sqrt(1/(nrow(U)-1))*(L %*% t(A)))
colnames(H) <- sprintf("dim%d", seq(1:2))
rownames(H) <- sprintf("F%d", seq(1:9))
H

## analisis biplot
biplot(G,H, expand = 1)

## cek apakah benar
X <- G %*% t(H)
X

error <- abs(dt - X)
error
