# Data Frame
#Membuat Data Frame
bulan <- c('April','Mei','Juni','Juli','Agustus','September','Oktober','November','Desember')
konfirmasi <- c(951, 4829, 12099, 22070, 33524, 43725, 52446, 61864, 84133)
meninggal <- c(100, 412, 928, 1711, 2370, 3192, 3768, 4407, 5827)
df <- data.frame(bulan, konfirmasi, meninggal)
df$bulan

# simpan Rdata 
# save(df, file=“latihan1.Rdata”)
# load("C:/Users/TOBI/Documents/Belajar_R/latihan1.Rdata")
# data = read.csv("C:/Users/TOBI/Documents/Belajar_R/data1.csv", header = FALSE, sep = ",")

# Line Chart
konfirmasi = df$konfirmasi
meninggal = df$meninggal
chart_range <- range(0,konfirmasi,meninggal)
plot(konfirmasi,type="o",col="red",ylin=chart_range,axes=FALSE,ann=FALSE)
axis(1,at=1:9,lab=bulan)
axis(2,las=1,at=9348*0:chart_range[2])
box()
lines(meninggal,type='o',pch=22,lyt=2,col="blue")
title(main="Grafik Terkonfirmasi dan Meninggal Pasien COVID-19\ndi Jawa Timur Tahun 2020",
      col.main="black",font.main=4)
title(xlab="Bulan",col.lab=rgb(0,0.5,0))
title(ylab="Jumlah",col.lab=rgb(0,0.5,0))
legend(1,chart_range[2]-   1,c("konfirmasi","meninggal"),cex=0.8,col=c("red","blue"),pch=21:22,lty=1:2)

# Histogram 
dataset <- data.frame(df$konfirmasi,df$meninggal)
names(dataset)<-c('Konfirmasi', 'Meninggal')
barplot(as.matrix(dataset),main = "Data Covid-19 Di Jawa Timur", ylab ="Jumlah",beside = TRUE,col = "red")
