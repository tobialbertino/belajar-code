# List Dalam Prolog
buatlah program fungsional untuk menghitung banyaknya elemen list yang merupakan kelipatan dari suatu bilangan tertentu yang tidak nol.

### Format Masukan
Input program terdiri atas dua entitas, yaitu suatu bilangan bulat positif, dan sebuah list di bawahnya.

### Format Keluaran
Sebuah bilangan bulat yang menyatakan banyaknya elemen list sesuai ketentuan dalam soal. Output diakhiri dengan newline.

### Contoh Masukan
```
4.
[4, 20, 2, 3, 5, 10, 12].
```

### Contoh Keluaran
```
3
```

### Penjelasan
Ada tiga elemen list yang merupakan kelipatan 4, yaitu 4, 20, dan 12.

### Code
```
program :- read(A), read(List), element(A,List,Sum), write(Sum), nl.
element(_,[],0).
element(A,[H|T],Total):- (H mod A) =:= 0, element(A,T,Sum), Total is Sum + 1.
element(A,[H|T],Total):- (H mod A) =\= 0, element(A,T,Total).
:- program.
```
