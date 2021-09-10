f = function(x) {
  (x^3) - (2 * x) - 5
}

p0 = 2.090798
p1 = 2.094592

fp0 = f(p0)
fp1 = f(p1)

p2 = p1 - (fp1 * (p1 - p0) / (fp1 - fp0))
ebs = p1 - p0
p2
ebs