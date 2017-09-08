def adj_uniq(L):
    import itertools
    
    pairs         = itertools.zip_longest(L, L[1:])
    non_dup_pairs = filter(lambda args: (lambda x, y: x != y)(*args), pairs)
    uniq_values   = map(lambda args: (lambda x, _y: x)(*args), non_dup_pairs)

    return uniq_values

lists = [[0],
         [1, 1, 1],
         [0, 0, 1, 1, 2, 1, 2, 1, 0],
         [0, 0, 1, 1, 2, 1, 2, 1, 0, 1],
         [0, 0, 1, 1, 2, 1, 2, 1, 0, 0]]

for L in lists:
    print([*adj_uniq(L)])
