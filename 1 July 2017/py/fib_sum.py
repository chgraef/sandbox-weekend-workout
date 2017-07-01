def fib(n):
    if n < 1:
        raise ArgumentError(
            'The numbering in the Fibonacci sequence starts at 1'
        )

    cur, nxt = 0, 1
    yield cur

    for _ in range(n):
        cur, nxt = nxt, cur + nxt
        yield cur

def fibsum(n):            
    return sum(fib(n))
