def partition_rec(L, fn):
    if len(L) == 0:
        return [[], []]

    x, rest = L[0], partition_rec(L[1:], fn)
    left, right = rest

    return ([[x] + left, right] if fn(x)
                                else [left, [x] + right])

values = [*range(10)]
result = partition_rec(values, lambda x: x < 5)

print(result)
