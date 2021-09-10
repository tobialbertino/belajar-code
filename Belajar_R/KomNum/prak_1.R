f <- function(x) {
  4 * (x^3) + 3 * (x^2)
}

install.packages("Deriv")
library(Deriv)

#Turunan Pertama
turunan1 <- Deriv(f)
turunan1
turunan1(0.2)

#Turunan Kedua
turunan2 <- Deriv(turunan1)
turunan2
turunan2(0.2)

#Galat absolute
s <- 1
p <- 1
error_absolute <- function(s, p) {
  return(abs(s - p))
}
error_absolute(s, p)

#Galat relatif turunan pertama
error_relatif <- function(s, p) {
  return(abs((s - p) / s) * 100)
}
(error_relatif(s, p))