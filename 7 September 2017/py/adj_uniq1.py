# LISP-ish style.
def adj_uniq(L):
    import itertools
    return map(lambda args: (lambda x, _y: x)(*args),
               filter(lambda args: (lambda x, y: x != y)(*args),
                  itertools.zip_longest(L, L[1:])))

lists = [[0],
         [1, 1, 1],
         [0, 0, 1, 1, 2, 1, 2, 1, 0],
         [0, 0, 1, 1, 2, 1, 2, 1, 0, 1],
         [0, 0, 1, 1, 2, 1, 2, 1, 0, 0]]

for L in lists:
    print([*adj_uniq(L)])
