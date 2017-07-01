def priority_sorted(seq, priorities):
    '''
    Sorts 'seq' based on keys provided in 'priorities'.

    The first element in 'priorities' should exist in 'seq' and has a
    higher priority than the second element, the second element has a
    higher priority than the third and so on. If 'seq' has a value that
    does not occur in 'priorities', it will be sorted in the conventional
    manner.

    Example:
    Sorting a basket of fruits and vegetables. Mangos have to go first,
    followed by bananas, the rest of the contents of the basket have to
    be sorted in the conventional manner:

    basket =
        ['orange', 'banana', 'tomato', 'passionfruit', 'mango', 'mango']

    Should produce:
    
    baset =
        ['mango', 'mango', 'banana', 'orange', 'passionfruit', 'tomato']
    '''

    from collections import defaultdict

    lowest_priority = len(priorities)
    priority_lookup = defaultdict(
        lambda: lowest_priority, ((x, i) for i, x in enumerate(priorities))
    )

    return sorted(seq, key=lambda x: (priority_lookup[x], x))
    
