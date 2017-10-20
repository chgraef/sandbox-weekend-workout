compose = (lambda *funcs:
           (lambda f, *rest:
            (lambda *args: f(*args)) if len(rest) == 0
                else (lambda *args: f(compose(*rest)(*args))))(*funcs))

import math

print(list( 
    map(compose(math.sqrt, lambda y: y ** 2), range(-5, 0))))
