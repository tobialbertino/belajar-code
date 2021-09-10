# read data
ins <- read.csv("C:/Users/TOBI/Documents/Belajar_R/Daming/Dataset/insurance.csv")
str(ins)

# statistika ringkasan
summary(ins$age)

# standart deviasi 
sd(ins$age)

# visualisasi data 
boxplot(ins$bmi, main="Boxplot of Insurance BMI", ylab = "BMI")
hist(ins$charges, main="Histogram of Insurance Charges", xlab = "Charges")
plot(x=ins$bmi, y=ins$charges, main="Scatterplot of BMI vs Charges", xlab="BMI", ylab="Charges")
plot(density(ins$bmi), main="Density Plot For Insurance BMI")

# data multiple variabel 
cov(ins$age, ins$bmi)
cov(ins[, c("age", "bmi", "children", "charges")])
cor(ins$age, ins$bmi)
cor(ins[, c("age", "bmi", "children", "charges")])

aggregate(bmi ~ sex, summary, data = ins)

# Boxplot
boxplot(bmi ~ age, data = ins)
# Scatter plot
with(ins, plot(age, bmi, col=sex, pch=as.numeric(sex))
# Scatter plot with jitter
with(ins, plot(jitter(children), jitter(age)))
# Scatter plot with ggplot2
library(ggplot2)
qplot(age, charges, data = ins, facets = sex ~ .)

# Static 3D scatter plot
library(scatterplot3d)
with(ins, scatterplot3d(age, bmi, charges))
# Interactive 3D scatter plot
library(rgl)
with(ins, plot3d(age, bmi, charges))

# Pairs plot
pairs(ins[, c("age", "bmi", "children", "charges")])

# Heat map
distMatrix <- as.matrix(dist(ins[, c("age", "bmi",
"children", "charges")])
heatmap(distMatrix)

# Level plot
library(lattice)
levelplot(children ~ bmi * age, ins, cuts = 5,
col.regions = grey.colors(6)[6:1])

# Contour
filled.contour(volcano, color = terrain.colors, asp = 1,
plot.axes = contour(volcano, add = T))

# 3D surface
persp(volcano, theta = 25, phi = 30, expand = 0.5, col =
"lightblue")

# Parallel coordinates
library(MASS)
parcoord(ins[, c("age", "bmi", "children", "charges")],
col = ins$sex)
# Parallel coordinates with lattice
library(lattice)
parallelplot(~ins[, c("age", "bmi", "children",
"charges")] | sex, data = ins)

# Save as a PNG file
png("myPlot.png")
plot(1:10, log(1:10))
graphics.off()
# Save as a JPEG file
jpeg("myPlot.jpeg")
plot(1:10, log(1:10))
graphics.off()
# Save as a PDF file
pdf("myPlot.pdf")
plot(1:10, log(1:10))
graphics.off()
# Save as a Postscript file
postscript("myPlot.ps")
plot(1:10, log(1:10))
graphics.off()