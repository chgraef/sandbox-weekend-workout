def threes_and_sevens(x):
    '''
    Yep, that's a reference to the QOTSA song.

    Return a list of values in range (1, x), in which each value
    is not simultaneously divisible by 3 and 7.
    '''

    return [y for y in range(x) if not any(y % div == 0 for div in [3, 7])]
