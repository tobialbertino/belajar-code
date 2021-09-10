library(Deriv)

f = function(x) {
    1 / (1 + exp(-x))
}
a = f(-0.2758)
a

df = Deriv(f)
b = df(0.4)
b
