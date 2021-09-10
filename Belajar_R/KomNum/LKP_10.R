# Kaidah Trapesium
trapesium <- function(f, awal, akhir, n) {
  h <- (akhir - awal) / n
  xi <- seq.int(awal, akhir, h)
  xi <- xi[2:n]
  # xi <- xi[-1]
  # xi <- xi[-length(xi)]
  hasil <- (h / 2) * (f(awal) + 2 * sum(f(xi)) + f(akhir))
  # return(xi)
  return(hasil)
}

# Kaidah Simpson(1/3)
simpson <- function(f, awal, akhir, n) {
  h <- (akhir - awal) / n
  xi <- seq.int(awal, akhir, h)
  xi <- xi[2:n]
  # xi <- xi[-1]
  # xi <- xi[-length(xi)]
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
# -------------------------------------------
# No 2
f <- function(x) {
  2 * exp(x^2)
}
awal = 0
akhir = 1
n = 8
trapesium(f, awal, akhir, n)
# -------------------------------------------
# No 3
f <- function(x) {
  x / (1+(x^2))
}
awal = 1
akhir = 3
n = 8
simpson(f, awal, akhir, n)