data = read.csv("C:/Users/TOBI/Documents/Belajar_R/Daming/Dataset/diabetes.csv", header = FALSE, sep = ";")

write.table(data,file="diabetes2.csv",sep=",",dec = " ")