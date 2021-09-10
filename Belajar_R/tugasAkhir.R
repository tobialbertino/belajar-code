library(factoextra)
library(ggplot2)

#Import Data
data=read.csv("dataset.csv", header=TRUE)

#Ambil Umur, Pendapatan Tahunan, Skor pengeluaran
dt <- data[3:5]

#Standarisasi Data
rge<- sapply(dt, function(x) diff(range(x)))
stddt<- sweep(dt, 2, rge, FUN = "/")

#Cari K Optimal
fviz_nbclust(stddt, kmeans, method = "wss")
fviz_nbclust(stddt, kmeans, method = "silhouette")

#Clustering dengan k-means
clustering = kmeans(stddt,centers=8,nstart=25)
fviz_cluster(clustering, geom = "point", data = stddt)+ggtitle("k=8")