program :- read(A), read(B), read(C), operasi(A,B,C,D), write(D), nl.
operasi(A,B,0,D):- D is A * B. 
operasi(A,B,C,D):- D is A + B + C.
:- program.