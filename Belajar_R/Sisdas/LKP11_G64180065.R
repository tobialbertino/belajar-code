fungsi = function(x) {
  (2*(x^2)) + (4*x) + 5
}
N = 4
x = c(-4, -3, 2, 5)
v = c(0, 0, 0, 0)
c1 = c2 = 1
omega = c(0.77, 0.58, 0.42, 0.26, 0.1)
r1 = c(0.1, 0.1, 0.4, 0.2, 0.7)
r2 = c(0.2, 0.1, 0.4, 0.6, 1)
iteration = 5

# inisiasi 
fitness = fungsi(x)
pbest = x
gbest = x[which.min(fitness)]
pbest_fitness = fungsi(x)
gbest_fitness = fungsi(gbest)
fitness
pbest
gbest
pbest_fitness
gbest_fitness

# iteration 
for (i in 1:iteration) {
  print(paste0("Iterasi: ", i))
  # update velocity/iteration 
  for (j in 1:N) {
    v[j] = omega[i] * v[j] + c1*r1[i]*(pbest[j] - x[j]) +
            c2*r2[i]*(gbest - x[j])
    x[j] = x[j] + v[j]
  }
  print(paste0("nilai x:"))
  print(x)
  print(paste0("nilai v:"))
  print(v)

  # update pbest & gbest/iteration 
  fitness = fungsi(x)
  for (j in 1:N) {
    if(fitness[j] < pbest_fitness[j]) {
      pbest[j] = x[j]
      pbest_fitness[j] = fitness[j]
    }
    if(fitness[j] < gbest_fitness) {
      gbest = x[j]
      gbest_fitness = fitness[j]
    }
  }
  
  print(paste0("fitness : "))
  print(fitness)
  print(paste0("pbest : "))
  print(pbest)
  print(paste0("gbest : "))
  print(gbest)
  cat('\n')
}

