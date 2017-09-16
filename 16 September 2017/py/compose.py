def compose(*args):
    if len(args) == 0:
        return lambda x: x

    f, *rest = args
    return lambda x: (compose(*rest)(f(x)))

foo = lambda x: x + 1
bar = lambda x: x - 2

f = compose(foo, bar)
y = 0
x = f(y)

print(x)
print('Success...')

