# Data Frame
# Membuat Data Frame
atribut1 <- c(2, 4, 7, 3, 6)
atribut2 <- c(6, 3, 5, 2, 6)
df <- data.frame(atribut1, atribut2)
df

write.csv(df,"C:/Users/TOBI/Documents/Belajar_R/Daming/Dataset/soal5_new.csv",row.names = FALSE)
