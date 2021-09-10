library(Deriv)
# No 1 : Metode Bagi Dua
f <- function(x) {
  exp(x) - 2 - x
}
a <- -3
f(-1.78125)
b <- -1.5
f(b)
c <- (a + b) / 2
epsilon <- 0.001
n <- as.integer(log((b - a) / epsilon) / log(2)) + 1
n
# bisection
bisection <- function(f, a, b, c, epsilon, n) {
  mat_a <- NULL
  mat_b <- NULL
  mat_c <- NULL
  mat_ba <- NULL
  mat_fc <- NULL
  # loop selama n X
  for (i in 1:n) {
    c <- (a + b) / 2
    mat_a[i] <- a
    mat_b[i] <- b
    mat_c[i] <- c
    mat_ba[i] <- abs(b - c)
    mat_fc[i] <- f(c)
    if (f(c) == 0) {
      break
    }
    else if (f(a) * f(c) < 0) {
      b <- c
    }
    else {
      a <- c
    }
    # periksa apakah [b-c] < epsilon
    if (abs(b - a) < epsilon) {
      break
    }
  }
  # buat matriks
  matriks <- matrix(c(mat_a, mat_b, mat_c, mat_ba, mat_fc),
                    ncol = 5, dimnames = list(NULL, c("a", "b", "c",
                                                      "b-c", "f(c)")))
  return(matriks)
}
bisection(f, a, b, c, epsilon, n)

# _____________________________________________________________________
# No 2
f <- function(x) {
  (5 * x^3) - (10 * x^2) + (5 * x) - 8
}
a <- -1
b <- 3.0000000
epsilon <- 0.0001
n <- 20
# regula_falsi
regula_falsi <- function(f, a, b, c, epsilon, n) {
  mat_a <- NULL
  mat_b <- NULL
  mat_c <- NULL
  mat_ba <- NULL
  mat_fc <- NULL
  # loop selama n X
  for (i in 1:n) {
    c <- b - ((f(b) * (b - a)) / (f(b) - f(a)))
    mat_a[i] <- a
    mat_b[i] <- b
    mat_c[i] <- c
    mat_ba[i] <- abs(b - a)
    mat_fc[i] <- f(c)
    if (f(c) == 0) {
      break
    }
    else if (f(a) * f(c) < 0) {
      b <- c
    }
    else {
      a <- c
    }
    # periksa apakah [b-c] < epsilon
    if (abs(b - a) < epsilon) {
      break
    }
  }
  matriks <- matrix(c(mat_a, mat_b, mat_c, mat_ba, mat_fc),
                    ncol = 5, dimnames = list(NULL, c("a", "b", "c",
                                                      "b-a", "f(c)")))
  return(matriks)
}
regula_falsi(f, a, b, c, epsilon, n)
