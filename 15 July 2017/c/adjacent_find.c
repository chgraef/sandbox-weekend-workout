#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/*
    adjacent_find

    Searches the range [first,last) for the first occurrence of two consecutive elements 
    that match, and returns an iterator to the first of these two elements, or last if no 
    such pair is found.
*/

const int *adjacent_find(const int *begin, const int *end);

static void test_0(void);
static void test_1(void);
static void test_2(void);
static void test_3(void);
static void test_4(void);
static void test_5(void);
static void test_6(void);

typedef void (*Test)(void);

int main(void)
{
    const Test Tests[] = {
        &test_0, &test_1,
        &test_2, &test_3,
        &test_4, &test_5,
    };

    const size_t TestCount = sizeof(Tests)/sizeof(Tests[0]);

    for (size_t index = 0; index < TestCount; ++index) {
        const Test cur_test = Tests[index];
        (*cur_test)();
    }

    (void)printf("%zd tests passed. Success...", TestCount);

    return EXIT_SUCCESS;
}

const int *adjacent_find(const int *begin, const int *end)
{
    if (!begin) return NULL;
    if (!end)   return NULL;

    if (begin < end)
    {
        for (const int *cur_elem = &begin[1]; cur_elem != end; ++cur_elem)
        {
            if (cur_elem[-1] == cur_elem[0]) {
                return &cur_elem[-1];
            }
        }
    }

    return end;
}

static void test_0(void)
{
    const char *const Description = 
        "Returns a falsy value when the \"begin\" param is NULL.";

    (void)puts(Description);

    const int        value  = 0xc0ffee;
    const int *const actual = adjacent_find(NULL, &value);

    assert(!actual);
}

static void test_1(void)
{
    const char *const Description = 
        "Returns a falsy value when the \"end\" param is NULL.";

    (void)puts(Description);

    const int        value  = 0xc0ffee;
    const int *const actual = adjacent_find(&value, NULL);

    assert(!actual);
}

static void test_2(void)
{
    const char *const Description = 
        "Returns the \"end\" pointer if there's only one element in a sequence.";

    (void)puts(Description);

    const int        values[] = { 0xc0ffee };
    const size_t     count    = sizeof(values)/sizeof(values[0]);

    const int *const begin    = &values[0];
    const int *const end      = &values[count];

    const int *const actual   = adjacent_find(begin, end);

    assert(actual == end);
}

static void test_3(void)
{
    const char *const Description = 
        "Returns the \"end\" pointer if there are no duplicates in a sequence.";

    (void)puts(Description);

    const int        values[] = { 0, 1, 2, 3, 5, 8, 13 };
    const size_t     count    = sizeof(values)/sizeof(values[0]);

    const int *const begin    = &values[0];
    const int *const end      = &values[count];

    const int *const actual   = adjacent_find(begin, end);

    assert(actual == end);
}

static void test_4(void)
{
    const char *const Description = 
        ("Returns the pointer to the first repeated element "
         "in a sequence. Only one repeated subsequence available.");

    (void)puts(Description);

    const int        values[] = { 0, 1, 1, 2, 3, 5, 8, 13 };
    const size_t     count    = sizeof(values)/sizeof(values[0]);

    const int *const begin    = &values[0];
    const int *const end      = &values[count];

    const int *const expected = &values[1];
    const int *const actual   = adjacent_find(begin, end);

    assert(actual == expected);
}

static void test_5(void)
{
    const char *const Description = 
        ("Returns the pointer to the first repeated element in a "
         "sequence. More than one repeated subsequence available.");

    (void)puts(Description);

    const int        values[] = { 0, 1, 1, 2, 3, 3, 8, 13 };
    const size_t     count    = sizeof(values)/sizeof(values[0]);

    const int *const begin    = &values[0];
    const int *const end      = &values[count];

    const int *const expected = &values[1];
    const int *const actual   = adjacent_find(begin, end);

    assert(actual == expected);
}

static void test_6(void)
{
    const char *const Description = 
        ("Returns the pointer to the first repeated element in a "
         "sequence. All elements are equal inside the sequence are equal.");

    (void)puts(Description);

    const int        values[] = { 0, 0, 0, 0, 0, 0, 0, 0 };
    const size_t     count    = sizeof(values)/sizeof(values[0]);

    const int *const begin    = &values[0];
    const int *const end      = &values[count];

    const int *const expected = &values[0];
    const int *const actual   = adjacent_find(begin, end);

    assert(actual == expected);
}
