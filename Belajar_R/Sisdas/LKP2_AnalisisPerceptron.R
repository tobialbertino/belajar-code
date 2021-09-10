library(rgl)

# Random.Unit returns n dim-dimensional points in the unit interval labeled
# -1 or 1. The label depends on whether or not the sum of the vector's 
# components exceeds the given threshold. That is, -1 if sum(vector) < threshold
# and 1 otherwise.
# fungsi untuk membuat data random dengan argumen(n, dimensi, treshold) 
Random.Unit <-function(n, dim, threshold) {
  # membuat bilanganc random [0-1] sebanyak n * dimensi
  points <- runif(n * dim)
  # mengubah kedalam bentuk matriks, jmlh kolom=dimensi
  points <- matrix(points, ncol = dim)
  # memberi nama label -1 / 1 pada tiap titik sesuai nilai treshold 
  label <- ifelse(apply(points, 1, sum) < threshold, -1, 1)
  # mengembalikan nilai matriks yg sudah diberi dilabel
  return(cbind(label, x0 = rep(1, n), points))
}

# Classify is our simple classification rule for the perceptron.We simply 
# return the sign of the dot-product of our observations and weights
# fungsi classify argumen (x, bobot)
Classify <- function(x, weights) {
  # Mengembalikan nilai yang sesuai dengan bobot yang baru 
  return(sign(x %*% weights))
}

# Perceptron is a simple implementation of the perceptron learning algorithm.
# It accepts data of the form data[1] = label, data[2] = x_0 = 1, data[3] = x_1,
# etc. w0 is initilized to -threshold and the weights returned are such that
# sign(w_0 * x_0 + w_1 * x_1 + ... + w_n * x_n) == label
# fungsi perceptron argumen(dataMatrix, treshold)
Perceptron <- function(data, threshold) {
  # menghitung nilai awal, w[-treshold, acak]
  w <- c(-threshold, runif(ncol(data) - 2))
  # mengambil jumlah baris data matriks 
  n <- nrow(data)
  # ambil label yg dibuat, data[:, 0]
  label <- data[ , 1]
  # ambil obs yg dibuat, data[:, 1:ncol]
  obs <- data[ , 2:ncol(data)]
  # menganggap ada bilangan salah yang diberikan label 
  misclassfied <- TRUE
  while (misclassfied) {
    # mengubah label bilangan agar label menjadi lebih tepat
    misclassfied <- FALSE
    for (i in 1:n) {
      # Jika label i berbeda dengan nilai yang dikembalikan oleh
      # fs classify, maka bobot input diubah 
      if (label[i] * Classify(obs[i , ], w) <= 0) {
        w <- w + label[i] * obs[i , ]
        misclassfied <- TRUE
      }
    }
  }
  # mengembalikan nilai bobot 
  return(w)
}

# Plot3D is essentially a wrapper for the rgl package's plot3d function.
# It plots the result of a call to Random.Unit with dim = 3
# as well as the plane parameterized by ax + by + cz + d = 0
# fungsi untuk membuat plot 3D 
Plot3D <- function(points, a, b, c, d) {
  # visualisasi data 3D, 3 matriks terakhir= x, y, z
  plot3d(points[, 3:5], xlab = "X", ylab = "Y", zlab = "Z",
         pch = ifelse(points[, 1] == 1, 2, 8),
         col = ifelse(points[, 1] == 1, "blue", "red"))
  planes3d(a, b, c, d)
}

# Plot2D plots the result of a call to Random.Unit with dim = 2 as well
# as the line parameterized by y = bx + a, as in the call to abline.
# fungsi untuk membuat plot 2D 
Plot2D <- function(points, a, b) {
  # visualisasi data 2D, 2 matriks terakhir= x, y
  plot(points[, 3:4], xlab = "X", ylab = "Y",
       pch = ifelse(points[, 1] == 1, 2, 8),
       col = ifelse(points[, 1] == 1, "blue", "red"))
  abline(a, b)
}

# main program 
# tentukan nilai treshold 
THRESHOLD <- 1.5
# menentukan data random, sebanyak 1000 data
# 3 dimensi, & nilai treshold yg ditentukan 
pts <- Random.Unit(1000, 3, THRESHOLD)
# membuat plot 3D dengan argumen(data, a, b, c, d) 
Plot3D(pts, 1, 1, 1, -THRESHOLD)
# mengubah bobot dengan fungsi perceptron 
w <- Perceptron(pts, THRESHOLD)
# mencetak visualisasi setelah diubah perceptron 
Plot3D(pts, w[4], w[3], w[2], w[1])

# tentukan nilai treshold 
THRESHOLD <- 0.75
# menentukan data random, sebanyak 1000 data
# 2 dimensi, & nilai treshold yg ditentukan 
pts <- Random.Unit(1000, 2, THRESHOLD)
# membuat plot 3D dengan argumen(data, a, b)
Plot2D(pts, THRESHOLD, -1)
# mengubah bobot dengan fungsi perceptron
w <- Perceptron(pts, THRESHOLD)
# mencetak visualisasi setelah diubah perceptron 
Plot2D(pts, -w[1]/w[3], -w[2]/ w[3])