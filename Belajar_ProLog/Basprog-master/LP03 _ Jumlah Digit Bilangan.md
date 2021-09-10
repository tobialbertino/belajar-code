# Jumlah Digit Bilangan
Buatlah program logika Prolog untuk menghitung jumlah dari setiap digit penyusun suatu bilangan bulat. 
Sebagai contoh, jumlah digit dari 243 adalah 9 (yaitu 2+4+3).

### Format Masukan
Sebuah bilangan bulat.

### Format Keluaran
Sebuah bilangan bulat hasil perhitungan jumlah setiap digit penyusun bilangan masukan. Output diakhiri oleh newline.

### Contoh Masukan
```
243.
```

### Contoh Keluaran
```
9
```

### Code
```
program :- read(A), sumdigit(A,C), write(C), nl.
sumdigit(A,C):- (A // 10) =:= 0, C is A.  
sumdigit(A,D):- B is A mod 10, sumdigit(A div 10, C), D is C + B.  
:- program.
```

