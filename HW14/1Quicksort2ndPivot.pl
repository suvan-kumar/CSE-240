% Suvan Kumar
%
% Hint: You may want to consider how many base cases you might need and whether or not you'll need a helper function
qsort2([],[]).                                         % Empty list is already sorted
qsort2([X],[X]).                                       % List is just 1 element
qsort2([X | [Pivot|Tail]], Sorted):-                   % Take the second number as pivot
    split(Pivot, [X|Tail], L1, L2),                    % Call split/4 rule
    qsort2(L1, Sorted1),                               % Sort first partition
    qsort2(L2, Sorted2),                               % Sort second partition
    append(Sorted1, [Pivot|Sorted2], Sorted).          % Add onto Sorted



split(_,[],[],[]).                                     % Stopping condition
split(Pivot, [X|T], [X|Le], Gt) :-                     % Take first from tail
    X=<Pivot, 
    split(Pivot, T, Le, Gt).                           % Put it into Le
split(Pivot, [X|T], Le, [X|Gt]) :-                     % Take first from tail
    X>Pivot,
    split(Pivot, T, Le, Gt).                           % Put it into Gt

