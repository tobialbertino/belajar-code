library(party)
library(rpart)
library(rpart.plot)
library(caret)
library(e1071)

data = read.csv("C:/Users/TOBI/Documents/Belajar_R/Daming/Dataset/glass.csv")
data[, 'Type'] = as.factor(data[, 'Type'])
set.seed(1234)
ind <- sample(2, nrow(data), replace=TRUE, prob=c(0.7, 0.3))

train_data = data[ind==1, ]
test_data  = data[ind==2, ]

myFormula = Type ~ .
svm_model = svm(myFormula, data = train_data, cost=100, gamma=0.5)
summary(svm_model)

svm_pred = predict(svm_model, test_data)
svm_pred
confusionMatrix(svm_pred, test_data$Type)
