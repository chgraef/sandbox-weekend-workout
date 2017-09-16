def partition(fn, L):
    truthy = filter(fn, L)
    falsey = filter(lambda x: not fn(x), L)
    return (*map(list, [truthy, falsey]),)

def recursive_sum(L):
    from itertools import chain

    is_list = lambda x: hasattr(x, '__iter__')
    lists, items = partition(is_list, L)
    
    return sum(chain(items, map(recursive_sum, lists)))

print(recursive_sum(range(5)))
print(recursive_sum([1, 2, 3, [[[4]]], 0, -2]))
