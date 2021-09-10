library(Deriv)

# newton_raphson
newton_raphson <- function(f, df, x0, epsilon, n) {
  mat_x0 <- NULL
  mat_fx0 <- NULL
  mat_xn <- NULL
  mat_fxn <- NULL
  mat_beda <- NULL
  for (i in 1:n) {
    mat_x0[i] <- x0
    mat_fx0[i] <- f(x0)
    x <- x0 - (f(x0) / df(x0))
    mat_xn[i] <- x
    mat_fxn[i] <- f(x)
    beda <- abs((x - x0) / x)
    mat_beda[i] <- beda
    if (beda < epsilon) {
      break
    }
    x0 <- x
  }
  matriks <- matrix(c(mat_x0, mat_fx0, mat_xn, mat_fxn, mat_beda),
        ncol = 5, dimnames = list(NULL,
        c("x0", "f(x0)", "xn", "f(xn)", "xn-x0")))
  return(matriks)
}

# secant
secant <- function(f, x0, x1, epsilon, n) {
  mat_x0 <- NULL
  mat_x1 <- NULL
  mat_fx0 <- NULL
  mat_fx1 <- NULL
  mat_xn <- NULL
  mat_fxn <- NULL
  mat_beda <- NULL
  for (i in 1:n) {
    mat_x0[i] <- x0
    mat_x1[i] <- x1
    mat_fx0[i] <- f(x0)
    mat_fx1[i] <- f(x1)
    x <- (x1 - ((f(x1) * (x1 - x0)) / (f(x1) - f(x0))))
    mat_xn[i] <- x
    mat_fxn[i] <- f(x)
    beda <- abs((x1 - x0))
    mat_beda[i] <- beda
    if (beda < epsilon) {
      break
    }
    x0 <- x1
    x1 <- x
  }
  matriks <- matrix(c(mat_x0, mat_x1, mat_xn, mat_fxn, mat_beda),
        ncol = 5, dimnames = list(NULL,
        c("x0", "x1", "xn", "f(xn)", "xn-x0")))
  return(matriks)
}

# nomor 2
f1 <- function(x) {
  exp(x) / (x^2 - (4 * x))
}
secant(f1, 1, 2.5, 1.e-5, 15)
newton_raphson(f1, Deriv(f1), -1, 1.e-5, 15)

# nomor 3
f2 <- function(x) {
  exp(x) - (5 * x^2)
}
secant(f2, -1, 2, 1.e-2, 7)
newton_raphson(f2, Deriv(f2), -1, 1.e-2, 7)