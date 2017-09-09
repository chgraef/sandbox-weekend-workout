def longest_common_prefix(str1, str2):
    from itertools import takewhile
    return ''.join(
        map(lambda args: (lambda c1, c2: c1)(*args),            
            takewhile(lambda args: (lambda c1, c2: c1 == c2)(*args),
                      zip(str1, str2))))

lcp = longest_common_prefix('bananananana', 'bananas')
print(lcp)
