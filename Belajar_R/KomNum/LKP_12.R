# kaidah Gauss-Legendre 2-titik
library(gaussquad)

a = 0
b = 3
f = function(x) { 
  (x * exp(x)) + 1 
}
aktual = integrate(f, a, b)
aktual
# utk menggunakan kaidah Gauss-Legendre 2-titik, 
# Ubah fungsi 
a = -1
b = 1
f = function(t) {
  x = (3 + (3*t)) / 2
  dx = 3/2
  ((x * exp(x)) + 1) * dx
}
# daftar rule legandre n titik
# gunakan data untuk [[n]] titik
orthogonal.rules <- legendre.quadrature.rules(2)
orthogonal.rules
typeof(orthogonal.rules)
hasil = legendre.quadrature(f, orthogonal.rules[[2]], a, b)
hasil
# ____________________________________________________________
# No 2
library(Deriv)
selisih_maju = function(f, x, h) {
  n = (f(x+h) - f(x)) / h
  return(n)
}

selisih_mundur = function(f, x, h) {
  n = (f(x) - f(x-h)) / h
  return(n)
}

selisih_pusat = function(f, x, h) {
  n = (f(x+h) - f(x-h)) / (2*h)
  return(n)
}

galat = function(a, b) {
  return(abs(a - b))
}

f <- function(x) {
  exp(x)
}
# aktual
df = Deriv(f)
aktual = df(1)
aktual
# Untuk h = 0.1
h1 = 0.1
h1_maju = selisih_maju(f, x=1, h1)
h1_mundur = selisih_mundur(f, x=1, h1)
h1_pusat = selisih_pusat(f, x=1, h1)
h1_maju
h1_mundur
h1_pusat
galat(h1_maju, aktual)
galat(h1_mundur, aktual)
galat(h1_pusat, aktual)
# untuk h2 = 0.01
h2 = 0.01
h2_maju = selisih_maju(f, x=1, h2)
h2_mundur = selisih_mundur(f, x=1, h2)
h2_pusat = selisih_pusat(f, x=1, h2)
h2_maju
h2_mundur
h2_pusat
galat(h2_maju, aktual)
galat(h2_mundur, aktual)
galat(h2_pusat, aktual)
# untuk h2 = 0.01
h3 = 0.001
h3_maju = selisih_maju(f, x=1, h3)
h3_mundur = selisih_mundur(f, x=1, h3)
h3_pusat = selisih_pusat(f, x=1, h3)
h3_maju
h3_mundur
h3_pusat
galat(h3_maju, aktual)
galat(h3_mundur, aktual)
galat(h3_pusat, aktual)
# untuk h2 = 0.01
h4 = 0.0001
h4_maju = selisih_maju(f, x=1, h4)
h4_mundur = selisih_mundur(f, x=1, h4)
h4_pusat = selisih_pusat(f, x=1, h4)
h4_maju
h4_mundur
h4_pusat
galat(h4_maju, aktual)
galat(h4_mundur, aktual)
galat(h4_pusat, aktual)