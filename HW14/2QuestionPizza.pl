% Suvan Kumar
pizza(P,S,B,O,M) :-
    member(P, [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10]),                          % List for P with possible number of items
    member(S, [0, 1, 2, 3, 4]),                                             % List for S with possible number of items
    member(B, [0, 1, 2, 3, 4, 5, 6]),                                       % List for B with possible number of items
    member(O, [0, 1, 2, 3, 4, 5, 6, 7, 8]),                                 % List for O with possible number of items
    member(M, [0, 1, 2, 3, 4, 5]),                                          % List for M with possible number of items

    Weight is 4*P + 10*S + 6*B + 5*O + 7*M,                                 % Weighting for each member added together
    Weight =:= 40.                                                          % Weight must equal 40

/* 
In order [S,O,M] for pizza(1, S, 1, O, M),

[0,6,0], [1, 4, 0], [2, 2, 0], [3, 0, 0]

[M = S, S = 0, O = 6]
[M = 0, O = 4, S = 1]
[M = 0, O = S, S = 2]
[M = O, O = 0, S = 3]

*/

