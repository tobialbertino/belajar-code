jumlah(A,B,C,D) :- C=\=0, D is A+B+C.
jumlah(A,B,C,D) :- C=:=0, D is A*B.

program :- read(A), read(B), read(C), jumlah(A,B,C,D), write(D), nl.
:- program.