posganjil([],_,[]).
posganjil([H|T],Pos,[H|X]):- 1 is mod(Pos,2), Pos1 is Pos+1, posganjil(T,Pos1,X).
posganjil([_|T],Pos,X):- Pos1 is Pos+1, posganjil(T,Pos1,X).

program:- read(List), posganjil(List,1,X), write(X),nl.
:- program.