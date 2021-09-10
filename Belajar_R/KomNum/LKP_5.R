# Metode Eliminasi Gauss-Jordan
# options(scipen = 999)
gauss_jordan <- function(A, B) {
  n <- ncol(A)
  AB <- cbind(A, B)
  for (p in 1:n) {
    if (p == 1) {
      a <- abs(AB[, p])
    } else {
      a <- c(rep(0, p - 1), abs(AB[p:n, p]))
    }
    pivot <- which(a == max(a))[1]
    temp <- AB[p, ]
    AB[p, ] <- AB[pivot, ]
    AB[pivot, ] <- temp
    AB[p, ] <- AB[p, ] / AB[p, p]
    for (r in 1:n) {
      if (r != p) {
        m <- AB[r, p]
        AB[r, ] <- AB[r, ] - m * AB[p, ]
      }
    }
  }
  AB
}


# Matriks Balikan
modifikasi_gauss <- function(A, B) {
  n <- ncol(A)
  AB <- cbind(A, B)
  for (p in 1:n)
  {
    if (p == 1) {
      a <- abs(AB[, p])
    }
    else {
      a <- c(rep(0, p - 1), abs(AB[p:n, p]))
    }
    pivot <- which(a == max(a))[1]
    temp <- AB[p, ]
    AB[p, ] <- AB[pivot, ]
    AB[pivot, ] <- temp
    AB[p, ] <- AB[p, ] / AB[p, p]
    for (r in 1:n)
    {
      if (r != p) {
        m <- AB[r, p]
        AB[r, ] <- AB[r, ] - m * AB[p, ]
      }
    }
  }
  AB[, (n + 1):(2 * n)]
}

# matriks A
m_a <- c(
  5, -1, 1,
  5, -9, 3,
  -3, 2, 7
)
m_a <- matrix(c(m_a), byrow = T, nrow = 3, ncol = 3)
# matriks B
m_b <- c(9, -17, 23)
m_b <- matrix(c(m_b), byrow = T, nrow = 3, ncol = 1)
m_a
m_b

hasil <- gauss_jordan(m_a, m_b)
hasil
hasil[1:3, 4]
# matriks identitas
m_i <- diag(3)
m_i
invers <- modifikasi_gauss(m_a, m_i)
invers
hasil <- invers %*% m_b #  matrix multiplication between the two matrices
hasil