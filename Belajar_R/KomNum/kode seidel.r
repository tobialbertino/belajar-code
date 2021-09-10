# inisiasi matrix 
a <- matrix(c(
  3, 1, -1, 5,
  4, 7, -3, 20,
  2, -2, 5, 10
), byrow = T, nrow = 3)
options(digits = 6)

# inisiasi niali awal 
x<- c(0,0,0)

n=3                       #Jumlah baris
m=4                       #Jumlah kolom
for(itr in 1:100){    #Looping iterasi yang dilakukan
  big = 0
  for(i in 1:n){      #Looping baris
    s = 0.0
    for (j in 1:n){   #Looping per kolom pada baris
      
      if(i != j){     #Kondisi yang bukan variabel yang sama
        
        #Perhitungan variabel selanjutnya
        s <- s + a[i,j]*x[j]
      }
    }
    
    #Untuk perhitungan nilai pembagi dan nilai akhir variabel
    temp = (a[i,4]-s)/a[i,i]
    
    #Perhitungan batas galat (relative error)
    relerr = abs((temp-x[i])/temp)
    if(big < relerr){
      big <- relerr
    }
    x[i] = temp
  }
  
  #Mencetak hasil tiap iterasi
  print(paste("iteration no. ",itr,"x",x[1],"y",x[2],"z",x[3]))
  if(big<= 0.001){
  
  #Mencetak hasil akhir
    print(paste("coverges"))
    for (i in x){
      print(paste(i))
    }
    break(0)
  }
}