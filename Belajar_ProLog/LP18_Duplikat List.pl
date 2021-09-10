program:- read(Lin), read(N), dup(Lin, 1, N, Lout), write(Lout), nl.
dup([], _, _, []) :- !.
dup([H|Tin], I, N, [H|Tout]) :- I < N, I1 is I + 1, dup([H|Tin], I1, N, Tout).
dup([H|Tin], I, N, [H|Tout]) :- I =:= N, dup(Tin, 1, N, Tout).
:- program.