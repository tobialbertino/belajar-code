# Kaidah Trapesium
trapesium <- function(f, awal, akhir, n) {
  h <- (akhir - awal) / n
  xi <- seq.int(awal, akhir, h)
  xi <- xi[2:n]
  hasil <- (h / 2) * (f(awal) + 2 * sum(f(xi)) + f(akhir))
  # return(xi)
  return(hasil)
}

# Kaidah Simpson(1/3)
simpson <- function(f, awal, akhir, n) {
  h <- (akhir - awal) / n
  xi <- seq.int(awal, akhir, h)
  xi <- xi[2:n]
  if (n == 2) {
    hasil <- (h / 3) * (f(awal) + 4 * sum(f(xi[seq.int(1, length(xi), 2)])) +
      f(akhir))
  }
  else {
    hasil <- (h / 3) * (f(awal) + 4 * sum(f(xi[seq.int(1, length(xi), 2)])) +
    2 * sum(f(xi[seq.int(2, length(xi), 2)])) + f(akhir))
  }
  return(hasil)
}
# ---------------------------------------------------------------------------
# No 2
f <- function(x, y) {
  (x * y) + ((x^2) * (y^3))
  # dydx
}
delta_x = 0.5
delta_y = 0.5
n = 4 # nx=ny=n
# No a
# Arah y delta y=delta x=0.5, n=4, metode simpson, arah x trapesium
simpson_arah_y <- function() {
  f <- function(y) {
    (x * y) + ((x^2) * (y^3))
  }
  x = 0 # saat x awal
  awal = 1
  akhir = 3
  delta_x = 0.5
  delta_y = 0.5
  n = 4
  hasil <- NULL
  for(i in 1:(n+1)) {
    hasil[i] <- simpson(f, awal, akhir, n)
    x = x + delta_x
  }
  return(hasil)
}
x = simpson_arah_y()
x
xi <- x[2:n]
trapesium_arah_x <- (delta_x/2) * (x[1] + (2*sum(xi)) + x[length(x)])
trapesium_arah_x
# ____________________________________________________
# No b
trapesium_arah_y <- function() {
  f <- function(y) {
    (x * y) + ((x^2) * (y^3))
  }
  x = 0 # saat x awal
  awal = 1
  akhir = 3
  delta_x = 0.5
  delta_y = 0.5
  n = 4
  hasil <- NULL
  for(i in 1:(n+1)) {
    hasil[i] <- trapesium(f, awal, akhir, n)
    x = x + delta_x
  }
  return(hasil)
}
x = trapesium_arah_y()
x
xi <- x[2:n]
# simpson arah x
hasil <- (delta_y/3) * (x[1] + 4 * sum(xi[seq.int(1, length(xi), 2)]) +
          2 * sum(xi[seq.int(2, length(xi), 2)]) + x[length(x)])
hasil