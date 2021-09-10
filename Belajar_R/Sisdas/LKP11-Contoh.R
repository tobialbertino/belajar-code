x = c(80, 90, 110, 75)
v = c(0, 0, 0, 0)
c1 = c2 = 1
omega = 1
r1 = 0.4
r2 = 0.5
fungsi = function(x) {
  ((100 - x)^2)
}
N = 4

# inisiasi 
fitness = fungsi(x)
pbest = x
gbest = x[which.min(fitness)]
pbest_fitness = fungsi(x)
gbest_fitness = fungsi(gbest)

# update velocity 
for (i in 1:N) {
  v[i] = omega*v[i] + c1*r1*(pbest[i]-x[i]) + c2*r2*(gbest-x[i])
  x[i] = x[i] + v[i]
}

# update pbest & gbest
fitness = fungsi(x)
for (i in 1:N) {
  if(fitness[i] < pbest_fitness[i]) {
    pbest[i] = x[i]
    pbest_fitness[i] = fitness[i]
  }
  if(fitness[i] < gbest_fitness[i]) {
    gbest[i] = x[i]
    gbest_fitness = fitness[i]
  }
}
pbest
gbest