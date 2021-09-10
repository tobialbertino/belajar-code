library(mice)

data = read.csv("C:/Users/TOBI/Documents/Belajar_R/Daming/Dataset/winequality-red.csv")
# No 1
is.null(data)
md.pattern(data)

# No 2
library(infotheo)
head(data)

# data$fixed.acidity = cut(data$fixed.acidity, 4, include.lowest = TRUE)
# data$fixed.acidity
# data$volatile.acidity = cut(data$volatile.acidity, 3, include.lowest = TRUE)
# data$volatile.acidity

# diskretisasi dengan library
ew.fixed.acidity =  discretize(data$fixed.acidity, "equalwidth", 4)
head(ew.fixed.acidity)
ew.volatile.acidity =  discretize(data$volatile.acidity, "equalwidth", 3)
head(ew.volatile.acidity)

# gabungkan kolom
data_baru = cbind(data, ew.fixed.acidity, ew.volatile.acidity)
names(data_baru)[13] = "ew.fixed.acidity"
names(data_baru)[14] = "ew.volatile.acidity"
head(data_baru)

# No 3 



#NOMOR 4
library("mice")

#baca data car_sales.csv dan car_sales2.csv
data1 <- read.csv("C:/Users/TOBI/Documents/Belajar_R/Daming/Datasetcar_sales.csv", header = TRUE, sep = ',')
data2 <- read.csv("C:/Users/TOBI/Documents/Belajar_R/Daming/Datasetcar_sales2.csv", header = TRUE, sep = ',')

#gabungkan data dan cek missing value
data <- rbind(data1, data2)
md.pattern(data)

#isi missing value dengan nilai mean
data$Price_in_thousands[is.na(data$Price_in_thousands)] <- mean(data$Price_in_thousands, na.rm = TRUE)
data$Engine_size[is.na(data$Engine_size)] <- mean(data$Engine_size, na.rm = TRUE)
data$Horsepower[is.na(data$Horsepower)] <- mean(data$Horsepower, na.rm = TRUE)
data$Wheelbase[is.na(data$Wheelbase)] <- mean(data$Wheelbase, na.rm = TRUE)
data$Width[is.na(data$Width)] <- mean(data$Width, na.rm = TRUE)
data$Length[is.na(data$Length)] <- mean(data$Length, na.rm = TRUE)
data$Curb_weight[is.na(data$Curb_weight)] <- mean(data$Curb_weight, na.rm = TRUE)
data$Fuel_capacity[is.na(data$Fuel_capacity)] <- mean(data$Fuel_capacity, na.rm = TRUE)
md.pattern(data)

summary(data)
