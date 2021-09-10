f = function(x) {
  (x^3) - (2 * x) - 5
}
df = function(x) {
  (3 * x^2) - 2
}

p0 = 2.094568
p1 = 2.094551

fp0 = f(p0)
dfp0 = df(p0)

value = p0 - (fp0 / dfp0)
ebs = (p1 - p0) / p1
p0
fp0
dfp0
value
ebs