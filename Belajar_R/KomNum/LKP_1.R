install.packages("Deriv")
library(Deriv)

# No 1
f = function(x) {
  ((2 * (x^3)) + (5 * (x^2))) / ((4 * sqrt(x)) + x)
}

# Turunan ke-1
df = Deriv(f)
df
df(0.6)

# Turunan Ke-2
ddf = Deriv(df)
ddf
ddf(0.6)

# Galat absolute
s = 1.8601640742453093
p = 1.860164
error_absolute = function(s, p) {
  return(abs(s - p))
}
error_absolute(s, p)

#Galat relatif turunan pertama
error_relatif = function(s, p) {
  return(abs((s - p) / s) * 100)
}
(error_relatif(s, p))

# ____________________________________________________
# No 2
g = function(y) {
  (y * cos(y) + 1) / (y^2 + 1)
  # y != 0
}
g(0.1)

# Galat absolute
s = 1.0000099998999983
p = 1.00001
error_absolute = function(s, p) {
  return(abs(s - p))
}
error_absolute(s, p)

#Galat relatif turunan pertama
error_relatif = function(s, p) {
  return(abs((s - p) / s) * 100)
}
(error_relatif(s, p))