# differential equation
# euler method
euler_PDB <- function(f, x0, y0, h, n) {
  x <- x0
  y <- y0

  for(i in 1:n) {
    y0 <- y0 + (h * f(x0, y0))
    x0 <- x0 + h
    x <- c(x, x0)
    y <- c(y, y0)
  }

  return(data.frame(x = x, y = y))
}

# heun method
heun_PDB <- function(f, x0, h0, h, n){
  x <- x0
  y <- y0

  for(i in 1:n) {
    # predictor
    y00 <- y0 + h * f(x0, y0)
    x00 <- x0 + h
    # corrector
    y01 <- y0 + h/2 * (f(x0, y0) + f(x00, y00))
    x0 <- x00
    y0 <- y01
    x <- c(x,x0)
    y <- c(y,y0)
  }

  return(data.frame(x = x, y = y))
}
# _______________________________________
# No 2
f <- function(x, y) {
  (x^2 * (y^2))
}
x0 = 0
y0 = 1
h = 0.2
n = 5
euler_PDB(f, x0, y0, h, n)
heun_PDB(f, x0, y0, h, n)