# set dir tempat kalian nyimpen gambar
# kalau pake komputer biasa, klik kanan di foldernya > properties > locationnya di copas
# terus \ diganti sama \\
# contoh : c:\\Users\\...
setwd("/cloud/project/edit(1)")

## library
library(OpenImageR)
library(jpeg)
library(colorspace)
library(matlib)
library(ggplot2)
library(factoextra)

## masukin data gambar
filenames <- list.files(pattern = "*.jpg", full.names = TRUE)
limage <- lapply(filenames, readJPEG)
length(limage)
# ANGKA YG KELUAR DISINI ITU BERAPA BANYAK GAMBAR YANG KEBACA

## ubah biar ga berwarna
# KALO MASIH BERWARNA GAMBARNYA JALANIN INI, YG BAWAHNYA GA USAH
for(i in 1:length(limage)){
  y <- rgb(limage[[i]][,,1], limage[[i]][,,2], limage[[i]][,,3])
  yg <- desaturate(y)
  limage[[i]] <- col2rgb(yg)[1, ]/255
}
# KALO GAMBARNYA UDH ITEM PUTIH JALANIN YG INI, YG ATAS GA USAH
for (i in 1:length(limage)){
	limage[[i]] <- as.vector(limage[[i]])
}

# gabungin semua gambar di 1 matriks
lg <- rbind(limage[[1]],limage[[2]])
for(i in 3:length(limage)){
	lg <- rbind(lg, limage[[i]]) 
}

# proses pca
pca <- prcomp(lg, center = TRUE)
summary(pca)
## catatan dari summary pca
# pca$sdev = akar dari nilai eigen
# pca$rotation = per kolomnya itu vektor eigen dari tiap nilai eigen
# contoh : nilai eigennya = pca$sdev[1], vektor eigen dari itu = pca$rotation[,1]

# ngitung proporsi, terus ambil q proporsi yang kumulatifnya > 90
vars <- apply(pca$x, 2, var)
prop <- vars/sum(vars)
for(i in 1:length(prop)){
  if(sum(prop[1:i]) > 0.9){
    break
  }
}
q <- i
q

# plot keragaman sumbu baru
prop <- t(as.matrix(prop[1:q]))
colnames(prop) <- c(1:q)
barplot(prop, main = "Proporsi tiap sumbu baru", ylab = "var", xlab = "dim")

# prop kalo 2 sumbu doang yg diambil
sum(prop[1:2])

# ambil eigen value dari proses pca (udah keurut dari yang terbesar)
eigval <- get_eig(pca)
barplot(eigval$eigenvalue, main = "Nilai Eigen", ylab = "nilai", xlab = "dim")

# ambil vector eigen dari q nilai eigen yg kepilih
selEigVec <- c()
for(i in 1:q){
  selEigVec <- cbind(selEigVec, pca$rotation[,i])
}

# transformasi data awal
y <- lg %*% selEigVec

### Transformasi data awal (kalo 2 sumbu doang)
selEigVec2 <- cbind(pca$rotation[,1], pca$rotation[,2])
y2 <- data.frame(lg %*% selEigVec2)
xx <- ggplot(y2, aes(X1, X2)) + geom_point(size = 2, shape = 3, color = "blue") + theme_bw() + labs(title = "Transformasi dari 2 sumbu baru")
print(xx)    # plot

### Plot data awal
y3 <- data.frame(lg)
xy <- ggplot(y3, aes(X1, X2)) + geom_point(size = 2, shape = 3, color = "blue") + theme_bw() + labs(title = "2 Sumbu Data Awal")
print(xy)  # plot