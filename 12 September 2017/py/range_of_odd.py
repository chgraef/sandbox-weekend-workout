def range_of_odd(n):
    if n == 1:
        return [1]

    rest = range_of_odd(n - 1)
    last = rest[-1] + 2

    return rest + [last]

odd_range = range_of_odd(13)
print(odd_range)
