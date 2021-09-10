prima(1,_,0).
prima(_,1,1).
prima(A,B,0):- (A mod B) =:= 0. 
prima(A,B,C):- (A mod B) =\= 0, B1 is B - 1, prima(A,B1,C).

program :- read(A), B is A div 2, prima(A,B,C), write(C), nl.
:- program.