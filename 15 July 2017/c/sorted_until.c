#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

/* Encapsulate "assert" inside a separate macro, in case
 * we want to re-route assertion to a different algorithm later.
 */
#define ASSERT(...) assert(__VA_ARGS__)

#define COUNT(ary) sizeof(ary)/sizeof(ary[0])
#define BEGIN(ary) &ary[0]
#define END(ary)   &ary[COUNT(ary)]

int         is_sorted               (const int *begin, const int *end);
const int  *is_sorted_until         (const int *begin, const int *end);
void        ary_print               (const int *begin, const int *end);
void        ary_underline_bad_order (const int *begin, const int *end);

int main(void)
{
    const int values[] = { 0, 24, 44, 666, 889, 77, 5, 3, 1 };

    ary_print(BEGIN(values), END(values));
    ary_underline_bad_order(BEGIN(values), END(values));

    (void)getchar();
    return EXIT_SUCCESS;
}

int is_sorted(const int *begin, const int *end)
{
    ASSERT(begin);
    ASSERT(end);
    ASSERT(begin <= end);

    if (begin != end)
    {
        for (const int *cur_item = begin; &cur_item[1] != end; ++cur_item)
        {
            if (cur_item[0] > cur_item[1]) {
                return 0;
            }
        }
    }

    return 1;
}

const int *is_sorted_until(const int *begin, const int *end)
{
    ASSERT(begin);
    ASSERT(end);
    ASSERT(begin <= end);

    if (begin != end)
    {
        for (const int *cur_item = begin; &cur_item[1] != end; ++cur_item)
        {
            if (cur_item[0] > cur_item[1]) {
                return &cur_item[1];
            }
        }
    }

    return end;
}

void ary_print(const int *begin, const int *end)
{
    ASSERT(begin);
    ASSERT(end);
    ASSERT(begin <= end);

    for (const int *cur_item = begin; cur_item != end; ++cur_item) 
    {
        const int item = *cur_item;
        (void)printf(" %d", item);
    }

    (void)putchar('\n');
}

void ary_underline_bad_order(const int *begin, const int *end)
{
    ASSERT(begin);
    ASSERT(end);
    ASSERT(begin <= end);

    const size_t SeparatorLength = 1;

    char buffer[1 + CHAR_BIT * sizeof(*begin)];

    const size_t     buffer_size   = sizeof(buffer)/sizeof(buffer[0]);
    const int *const sorted_before = is_sorted_until(begin, end);

    int total_width = SeparatorLength;

    for (const int *cur_value = begin; cur_value != sorted_before; ++cur_value)
    {
        const int value = *cur_value;
        (void)snprintf(buffer, buffer_size, "%d", value);

        const int width = strlen(buffer);
        total_width += width + SeparatorLength;
    }

    for (int col = 0; col < total_width; ++col) {
        (void)putchar('~');
    }

    (void)putchar('^');
    (void)putchar('\n');
}

