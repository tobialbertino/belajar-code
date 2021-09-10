program:- read(Lin), encode(Lin, Lout), write(Lout), nl.
encode([], []) :- !.
encode([A, A|Tin], [[A, N]|Tout]) :- encode([A|Tin], [[A,N1]|Tout]), N is N1 + 1.
encode([A, B|Tin], [[A, 1]|Tout]) :- encode([B|Tin], Tout).
encode([A|Tin], [[A, 1]|Tout]) :- encode(Tin, Tout).
:- program.