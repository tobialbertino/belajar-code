element(_,[],0).
element(A,[H|T],Total):- (H mod A) =:= 0, element(A,T,Sum), Total is Sum + 1.
element(A,[H|T],Total):- (H mod A) =\= 0, element(A,T,Total).

program :- read(A), read(List), element(A,List,Sum), write(Sum), nl.
:- program.