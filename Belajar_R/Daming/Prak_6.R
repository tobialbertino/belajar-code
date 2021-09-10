iris2 <- iris
iris2$Species <- NULL
(kmeans.result <- kmeans(iris2, 3))

table(iris$Species, kmeans.result$cluster)

plot(iris2[c("Sepal.Length", "Sepal.Width")], col = 
       kmeans.result$cluster)
points(kmeans.result$centers[,c("Sepal.Length",
      "Sepal.Width")], col = 1:3,pch = 8, cex=2)

library(fpc)
pamk.result <- pamk(iris2)

pamk.result$nc
table(pamk.result$pamobject$clustering, iris$Species)

layout(matrix(c(1,2),1,2)) # 2 graphs per page
plot(pamk.result$pamobject)
layout(matrix(1)) # change back to one graph per page

library(factoextra)
pam.result <- pam(iris2, 3)

table(pam.result$clustering, iris$Species)

layout(matrix(c(1,2),1,2)) # 2 graphs per page
plot(pam.result)
layout(matrix(1)) # change back to one graph per page

idx <- sample(1:dim(iris)[1], 40)
irisSample <- iris[idx,]
irisSample$Species <- NULL

hc <- hclust(dist(irisSample), method="ave")

plot(hc, hang = -1, labels=iris$Species[idx])
