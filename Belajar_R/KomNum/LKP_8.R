# install.packages("PolynomF")
library(PolynomF)
# Known values
x = c(10, 10.3)
y = log(x, base = 5)
# desired values
xExp = c(10.2)
xExp 
# Linear approximation 
approx(x, y, xExp)
x
y
# Linear approximation
apf = approxfun(x,y)
apf(xExp)
# ---------------------------------
# Interpoasi Polynom

# Known values
x = c(10, 10.1, 10.3)
y = log(x, base = 5)
# desired values
xExp = c(10.2)
require(PolynomF) 
polyf = poly_calc(x, y)
polyf(xExp)
# ---------------------------------
# nomor c
# Known values
x = c(0.0, 0.3, 0.6, 0.9)
y = cos(x) + 1
# desired values
xExp = c(0.7)
require(PolynomF) 
polyf = poly_calc(x, y)
polyf(xExp)

