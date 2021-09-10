# No 1
# read data
ins <- read.csv("C:/Users/TOBI/Documents/Belajar_R/Daming/Dataset/winequality-red.csv")
str(ins)

# No 2
# statistika ringkasan
ins <- read.csv("C:/Users/TOBI/Documents/Belajar_R/Daming/Dataset/forestfires.csv")
str(ins)

summary(ins)

# standart deviasi 
sd(ins$X)
sd(ins$Y)
sd(ins$FFMC)
sd(ins$DMC)
sd(ins$DC)
sd(ins$ISI)
sd(ins$temp)
sd(ins$RH)
sd(ins$wind)
sd(ins$rain)
sd(ins$area)

# No 4

#ins <- read.csv("forestfires.csv")

hist(ins$RH, main="Histogram of Forest Fires",
     xlab="RH")
hist(ins$temp, main="Histogram of Forest Fires",
     xlab="temp")

plot(x=ins$RH, y=ins$temp, main="Scatterplot of RH vs temp",
     xlab="RH", ylab="temp")
