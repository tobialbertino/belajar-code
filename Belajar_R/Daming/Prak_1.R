# Vektor
#Membuat Vektor
vec <- c(80, 50, 20, 92)
#Akses Vektor elemen ke-2
vec[2]

# Matriks
#Membuat Matriks
#3 baris, 3 kolom
mat <- matrix(1:9, nrow = 3, ncol = 3)
#Akses Matriks baris ke-2 dan kolom ke-3
mat[2,3]

# Array
#Membuat Array
arr <- array(1:27, dim = c(3,3,3))
#Akses Array dimensi ke-3
arr[,,3]

# Factor
#Membuat Factor (L : Laki-Laki, P : Perempuan)
fac <- factor(c('L','P','L','L','P'))

# List
lst <- list(id = c(44,13), name = c('FF','YSR'))
#Akses List id elemen ke-2
lst$id[2]

# Data Frame
#Membuat Data Frame
nama <- c('Dhery', 'Agus', 'Irfan')
nilai <- c(82, 80, 68)
df <- data.frame(nama,nilai)
#Akses kolom nilai
df$nilai

# 8. Import dan Export dataset ke dalam file csv
data = read.csv("~/latihan1.csv", header = FALSE, sep = ",")

no <- 1:6
x <- c(1256,1896,2012,989,1025,1506)
y <- c(1533,3281,2616,1597,1544,1789)
var <-data.frame(no,x,y)
write.csv(var,"~/latihan1.csv", row.names = FALSE)

# 9. Visualisasi Data
# Pie Chart
JumlahMobil <- c(1,2,5,7,9)
warna <- c("white", "grey70", "grey90", "grey50", "black")
labelmobil <- round(JumlahMobil/sum(JumlahMobil)*100,1)
labelmobil <- paste(labelmobil, "%", sep = "")
pie(JumlahMobil, main = "presentasi mobil di parkiran", col= warna, labels = labelmobil, cex=0.8)
legend(1.3, 0.5, c("Senin","Selasa","Rabu","Kamis","Jumat"),cex=0.7,fill=warna)

# Line Chart
JumlahMotor<-c(2,4,4,8,10)
g_range<-range(0, JumlahMotor,JumlahMobil)
plot(JumlahMobil, type="o", col="blue", ylin=g_range,axes=FALSE, ann=FALSE)
axis(1,at=1:5,lab=c("Senin","Selasa","Rabu","Kamis","Jumat"))
axis(2,las=1,at=4*0:g_range[2])
box()
lines(JumlahMotor,type='o',pch=22,lyt=2,col="red")
title(main="Kendaraan Bermotor", col.main="red",font.main=4)
title(xlab="Hari",col.lab=rgb(0,0.5,0))
title(ylab="Jumlah",col.lab=rgb(0,0.5,0))
legend(1,g_range[2]-1,c("Mobil","Motor"),cex=0.8,col=c("blue","red"), pch=21:22 ,lty=1:2)

# Histogram
var1 <- 1:5
var2 <- (1:5)/10
var3 <- c("kuda", "ayam", "kambing", "sapi", "tikus")
typeof(var1)
dataset <- data.frame(var1,var2,var3)
names(dataset)<-c("int", "float", "string")
dataset$string <- NULL
barplot(as.matrix(dataset),main = "coba coba", ylab ="total",beside = TRUE,col = rainbow(5))
legend("topleft", c("1","2","3","4","5"),cex = 0.6, bty ="n",fill=rainbow(5))