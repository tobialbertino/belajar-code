library(mice)
library(cluster)
library(fpc)


# baca data
data = read.csv("C:/Users/TOBI/Documents/Belajar_R/Daming/Dataset/train.csv")
is.null(data)
md.pattern(data)
head(data)
tail(data)

# No 4
# ambil 40 data, hapus variabel class 
idx <- sample(1:dim(data)[1], 40)
data_sample <- data[idx, ]
data_sample$class = NULL

# hierarchical clustering dengan metodenya
hc_single <-hclust(dist(data_sample), method="single")
hc_average <-hclust(dist(data_sample), method="ave")
hc_complete <-hclust(dist(data_sample), method="complete")

# plot
plot(hc_single, hang = -1, labels=data$class[idx])
plot(hc_average, hang = -1, labels=data$class[idx])
plot(hc_complete, hang = -1, labels=data$class[idx])
