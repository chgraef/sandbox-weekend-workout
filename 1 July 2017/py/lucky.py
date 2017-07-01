def is_lucky(x):
    '''
    I am not quite sure they are called "lucky numbers" per se but
    that's what they were called in the textbook.

    Return True if for a four-digit number in the format ABCD, the
    following equality holds: A + B == C + D.
    '''
    
    digits = [*map(int, str(x))]

    if len(digits) != 4:
        raise ArgumentError('Lucky number may only have 4 digits.')

    return sum(digits[:2]) == sum(digits[2:])
    
