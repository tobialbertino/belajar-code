program:- read(A), read(B), fpb(A,B,X), write(X),nl.
fpb(A,0,A).
fpb(A,B,X) :- A1 is B, B1 is mod(A,B), fpb(A1,B1,X). 
:- program.