program :- read(A), sumdigit(A,C), write(C), nl.
sumdigit(A,C):- (A // 10) =:= 0, C is A.  
sumdigit(A,D):- B is A mod 10, sumdigit(A div 10, C), D is C + B.  
:- program.