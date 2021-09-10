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

# runge kutta orde 4
rk4 <- function(f, x0, y0, h, n){
  x <- x0
  y <- y0
  
  for(i in 1:n){
    k1 <- f(x0,y0)
    k2 <- f(x0+0.5*h,y0+0.5*k1*h)
    k3 <- f(x0+0.5*h,y0+0.5*k2*h)
    k4 <- f(x0+h,y0+k3*h)
    y0 <- y0 + (1/6)*(k1+2*k2+2*k3+k4)*h
    x0 <- x0 + h
    x <- c(x, x0)
    y <- c(y, y0)
  }
  
  return(data.frame(x=x,y=y))
}
# ____________________________
# No 2
f = function(x, y) {
  (x - y) / 2
}
x0 = 0
y0 = 1
h = 1
n = 3
rk4(f, x0, y0, h, n)
# _____________________________
# No 3
f = function(x, y) {
  -2 * x * (y^2)
}
x0 = 0
y0 = 1
h = 0.25
n = 4
euler_PDB(f, x0, y0, h, n)
heun_PDB(f, x0, y0, h, n)
rk4(f, x0, y0, h, n)

