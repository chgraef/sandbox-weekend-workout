def generate_sieve(n):
    lookup = (*range(2, n),)
    result = lookup[:]

    for x in lookup:
        result = (*filter(lambda y: x == y or y % x != 0, result),)

    return result

limit = 102
sieve = generate_sieve(limit)

print(sieve)
