# install library
install.packages("usedist")
library(usedist)

# define function
fungsi_yuleq <- function(obj1, obj2) {
  # algoritme yuleq distance
  return(yuleq_distance)
}

# use dist_make()
d <- dist_make(x, fungsi_yuleq)

# make hierarchical clustering
fit <- hclust(d, method="complete")

# print dendogram
plot(fit) # display dendogram

# draw dendogram with red borders around the 5 clusters 
groups <- cutree(fit, k=3) # cut tree into 3 clusters
rect.hclust(fit, k=3, border="red")
