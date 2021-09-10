# Bilangan Prima
Buat program logika (Prolog) untuk menentukan apakah suatu bilangan tidak negatif yang dimasukkan merupakan bilangan prima atau bukan.
Jika merupakan bilangan prima, maka program akan menuliskan angka 1, sedangkan jika tidak maka program menuliskan angka 0. 
Perlu diingat kembali bahwa bilangan prima adalah bilangan bukan 1 yang hanya habis dibagi oleh 1 dan bilangan itu sendiri.

### Format Masukan 
Sebuah bilangan bulat positif.

### Format Keluaran
Angka 1 jika bilangan masukan adalah bilangan prima, atau angka 0 jika bilangan masukan bukan bilangan prima. Output diakhiri oleh newline.

### Contoh Masukan
```
6.
```

### Contoh Keluaran
```
0
```

#Code
```
program :- read(A), B is A div 2, prima(A,B,C), write(C), nl.
prima(1,_,0).
prima(_,1,1).
prima(A,B,0):- (A mod B) =:= 0, !. 
prima(A,B,C):- (A mod B) =\= 0, B1 is B - 1, prima(A,B1,C).
:- program.
```
