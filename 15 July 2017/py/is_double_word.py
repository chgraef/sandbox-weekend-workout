def is_double_word(word):
    if len(word) == 0:
        return False
    
    middle = len(word) // 2
    
    left   = word[:middle]
    right  = word[middle:]

    return left == right

def test_0():
    print('Returns False for an empty string')

    actual = is_double_word('')
    
    assert(actual == False)

def rand_test_0():
    def generate_word():
        import random
        import string
        
        MAX_LENGTH = 32
        CHAR_POOL  = string.ascii_lowercase
        
        IS_DOUBLE = False

        word = ''.join(c for c in random.choice(CHAR_POOL))

        return word, IS_DOUBLE

    def generate_double_word():
        IS_DOUBLE = True

        word = generate_word()

        return 2 * word, IS_DOUBLE

    import random

    TEST_COUNT = 32
    GENERATORS = (generate_word, generate_double_word)

    for times in range(TEST_COUNT):
        generator       = random.choice(GENERATORS)
        word, is_double = generator()
        actual          = is_double_word(word)
        
        assert(is_double == actual)

if __name__ == '__main__':
    TESTS      = (test_0, rand_test_0)
    TEST_COUNT = len(TESTS)

    for test in TESTS:
        test()

    print('{} tests passed successfully...'.format(TEST_COUNT))
    
