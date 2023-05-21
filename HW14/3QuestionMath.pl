% Suvan Kumar

%Hint: You may need to define multiples of the same rule.
foo(X,Y,F) :- 
    Y =< 0,                         % Stopping condition 1
    F is X,!.                       % Return value

foo(X,Y,F) :-
    X =< 0,                         % Stopping condition 2
    F is Y,!.                       % Return value

foo(X,Y,F) :-
    X >= Y,                         % If statement
    X1 is X-1,                      % Creating input for recursive call
    Y2 is Y-2,                      % Creating input for recursive call
    foo(X1,Y2,F1),                  % Size N-1 Problem
    F is X+F1.                      % Constructing size-N problem solution

foo(X,Y,F) :-
    X < Y,                          % If statement
    X2 is X-2,                      % Creating input for recursive call
    Y3 is Y-3,                      % Creating input for recursive call
    foo(X2,Y3,F1),                  % Size N-1 Problem
    F is Y+F1.                      % Constructing size-N problem solution
