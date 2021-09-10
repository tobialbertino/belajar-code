#Library buat model LVQ
library(class)
library(caret)
library(DMwR2)
library(e1071)

#Fungsi Normalisasi
normalize <- function(data){
  temp <- NULL
  for (i in data) {
    temp <- append(temp, (2*(i - min(data))/(max(data)-min(data))) - 1)
  }
  return(temp)
}

#Memasukkan dataset
df = read.csv("C:/Users/TOBI/Downloads/Sisdas/UTS sisdas/Dataframe_UTS-AGB.csv")
df$x1 <- normalize(df$x1)
df$x2 <- normalize(df$x2)
df$x3 <- normalize(df$x3)
df$kelas = as.factor(df$kelas)
View(df)

#isi NA dengan KNN imputation
df <- knnImputation(df)
View(df)

#Ambil 50% data train, 25% data validasi, 25% data uji 
#Split data test dan train
set.seed(69420)
index <- sample(1:nrow(df), round(0.5*nrow(df)))
train <- df[index,]
test <- df[-index,]

#Split Test menjadi validasi dan test
newindex <- sample(1:nrow(test), round(0.5*nrow(test)))
val <- test[newindex,]
test <- test[-newindex,]

#Merubah dataset menjadi matriks. 
train_m = data.matrix(train[, c("x1","x2","x3")])
test_m = data.matrix(test[, c("x1","x2","x3")])
val_m = data.matrix(val[, c("x1", "x2", "x3")])

train_label = factor(train[, "kelas"])
test_label = test$kelas
val_label = val$kelas

#Cari model terbaik
akurasi = NULL
alfa = NULL
for (i in 1:100) {
  #Memebuat codebook untuk LVQ
  codeBook = lvqinit(train_m, train_label, size = 100)
  buildCodeBook = olvq1(train_m, train_label, codeBook, alpha = i/100)
  
  #Melakukan prediksi
  predict = lvqtest(buildCodeBook, val_m)
  
  #menghitung akurasi
  sum = 0
  for (j in 1:length(predict)) {
    if(predict[j] == val_label[j]){
      sum = sum+1
    }
  }
  akurasi = append(akurasi, sum/length(val_label))
  alfa = append(alfa, i/100)
}
plot(alfa, akurasi)

#Mmebuat codebook untuk LVQ
codeBook = lvqinit(train_m, train_label, size = 100)
buildCodeBook = olvq1(train_m, train_label, codeBook, alpha = 0.19)

#Melakukan prediksi
predict = lvqtest(buildCodeBook, test_m)
confusionMatrix(test_label, predict)


