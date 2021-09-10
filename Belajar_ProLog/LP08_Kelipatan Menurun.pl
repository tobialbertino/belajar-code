program:- read(Lin), desc_mul(Lin, Lout), write(Lout),nl.
desc_mul([], []) :- !.
desc_mul([_, 0], []) :- !.
desc_mul([H, 1], [H]) :- !.
desc_mul([H, K], [R|Ti]) :- K > 1, R is H * K, K1 is K - 1, desc_mul([H, K1], Ti).
:- program.