def max_two(x, y):
    return (x if   y < x
              else y)

def max_rec(L):
    return (L[0] if len(L) == 1
                 else max_two(L[0], max_rec(L[1:])))
