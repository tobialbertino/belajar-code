library(PolynomF)
library(rSymPy)

# Piecewise Linear Interpolation
x <- c(0, 2, 6, 8, 10) # titik x
y <- c(0, 1.5, 1.5, 1, 2) # titik y
polyfit <- poly_calc(x, y) # mencari interpolasi piecwise polinomial
polyfit # hasilnya berupa fungsi
# --------------------------------------------

# Beda Terbagi Newton
newtonBagi2 <- function(x, y, x0) {
  require(rSymPy)
  n <- length(x)
  q <- matrix(data = 0, n, n)
  q[, 1] <- y
  f <- as.character(round(q[1, 1], 5))
  fi <- ""
  for (i in 2:n) {
    for (j in i:n) {
      q[j, i] <- (q[j, i - 1] - q[j - 1, i - 1]) / (x[j] - x[j - i + 1])
    }
    fi <- paste(fi, "*(x - ", x[i - 1], ")", sep = "", collapse = "")
    f <- paste(f, " + ", round(q[i, i], 5), fi, sep = "", collapse = "")
  }
  x <- Var("x")
  sympy(paste("e = ", f, collapse = "", sep = ""))
  approx <- sympy(paste("e.subs(x, ", as.character(x0), ")", sep = "", collapse = ""))
  return(list(
    "hasil P3(z)" = as.numeric(approx),
    "p3(x)" = f,
    "Tabel Terbagi Beda Newton" = q
    )
  )
}
x <- c(1, 2, 3, 4) # titik x
fx <- ax + b # fungsi
z <- r # titik yang ditanya
newtonBagi2(x, fx, z)
# No 2
x <- c(5, 2.5, 6.2, 7)
fx <- 2 * cos(x^2)
z <- 5.6
newtonBagi2 (x,fx,z)