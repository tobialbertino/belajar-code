gaus <- function(m_a, m_b) {
  n <- ncol(m_a) # ukuran kolom A nya harus persegi
  m_ab <- cbind(m_a, m_b) # menggabungkan 2 matriks
  for (p in 1:(n - 1)) {
    for (r in (p + 1):n) {
      m <- m_ab[r, p] / m_ab[p, p]
      m_ab[r, ] <- m_ab[r, ] - m * m_ab[p, ]
    }
  }
  return(m_ab)
}

m_a <- c(
  2, -1, 3, -1,
  -1, -2, -1, -1,
  3, 3, 1, 3,
  -2, 2, -2, 2)
# tempatinput matriks A
m_a <- matrix(c(m_a), byrow = T, nrow = 4, ncol = 4)

m_b <- c(11, -4, -2, 4)
m_b <- matrix(c(m_b), byrow = T, nrow = 4, ncol = 1)
# tempat input B

hasil <- gaus(m_a, m_b)
hasil
r <- hasil[1:4, 1:4] # upper Triangular m_a
x <- hasil[1:4, 5]   # upper Triangular m_b setelah gaus
backsolve(r, x, 4, upper.tri = TRUE)


# backsub <- function(a) {
#   n <- ncol(a) - 1
#   x <- rep(0, n) # replika 0 sebanyak n
#   for (i in n:1) {
#     if (i < n) {
#       temp <- 0
#       for (j in (i + 1):n) {
#         temp <- temp + a[i, j] * x[j]
#       }
#       x[i] <- a[i, n + 1] / a[i, n]
#     }
#     else {
#       x[i] <- a[i, n + 1] / a[i, n]
#     }
#   }
#   return(x)
# }

# backsub(hasil)

majusub <- function(a) {
  n <- ncol(a) - 1
  x <- rep(0, n) # replika 0 sebanyak n

  for (i in 1:n) {
    if (i > 1) {
      temp <- a[i, 1:n] %*% x
      x[i] <- (a[i, n + 1] - temp) / a[i, i]
    }
    else {
      x[i] <- a[i, n + 1] / a[i, 1]
    }
  }
  return(x)
}
majusub(hasil)
ul <- gaus(m_a, diag(4))
ul
# hasilnya yang kanan itu U, yang kiri  itu L

mat_lu <- function(m_a) {
  n <- ncol(m_a)
  m_l <- diag(n)
  for (p in 1:(n - 1)) {
    for (r in (p + 1):n) {
      m <- m_a[r, p] / m_a[p, p]
      m_l[r, p] <- m
      m_a[r, ] <- m_a[r, ] - m * m_a[p, ]
    }
  }
  return(cbind(m_l, m_a))
}

lu <- mat_lu(m_a)
lu
y <- backsub(cbind(lu[, 1:4], m_b))
x <- majusub(cbind(lu[, 5:8], y))
x
y
hasil