library(party)
library(rpart)
library(rpart.plot)
library(caret)
library(e1071)

data = data(iris)
data

set.seed(1234)
ind <- sample(2, nrow(data), replace=TRUE, prob=c(0.7, 0.3))

train_data = data[ind==1, ]
test_data  = data[ind==2, ]

myFormula = Species ~.
svm_model = svm(myFormula, data = train_data)
summary(svm_model)
# svm_model1 = svm(x_train, y_train)
# summary(svm_model)

svm_pred = predict(svm_model, test_data)
# svm_pred = as.factor(svm_pred)
# svm_pred
# test_data$Type
confusionMatrix(svm_pred, test_data$Type)

# test
# svm_pred = as.factor(svm_pred)
# test_data = as.factor(test_data)
# confusionMatrix(svm_pred, test_data$Type)
# confusionMatrix(factor(svm_pred, levels=min(test_data$Type):max(test_data$Type)), 
#                 factor(test_data$Type, levels=min(test_data$Type):max(test_data$Type)))
# pred = c(1,1,0,0)
# test = c(1,1,1,0)
# pred = as.factor(pred)
# test = as.factor(test)
# confusionMatrix(pred, test)
pred = c(1,1,0,0)
test = c(1,1,1,0)
pred = as.factor(pred)
test = as.factor(test)
confusionMatrix(pred, test)
