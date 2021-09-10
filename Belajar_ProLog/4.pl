gcd(A,0,A).
gcd(A,B,C) :- A1 is B, B1 is mod(A,B), gcd(A1,B1,C).

program :- read(A), read(B), gcd(A,B,C), write(C), nl.
:- program.