jumlah(A,A) :- A<10.
jumlah(A,B) :- C is mod(A,10), A1 is A//10, jumlah(A1,B1), B is C+B1.

program :- read(A), jumlah(A,B), write(B), nl.
:- program.