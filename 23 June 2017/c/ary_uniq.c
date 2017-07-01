#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <limits.h>

uint8_t *ary_uniq(const uint8_t *ary, size_t ary_size, size_t *res_size)
{
    if (!ary)		return NULL;
    if (!res_size)	return NULL;

    uint8_t lookup[UINT8_MAX] = { 0 };

    uint8_t *result = (uint8_t*)calloc(ary_size, sizeof(*result));
    *res_size = 0;

    if (result)
    {
        for (size_t index = 0; index < ary_size; ++index) {
            const uint8_t value = ary[index];
            ++lookup[value];
        }

        size_t uniq_count = 0;

        for (size_t index = 0; index < ary_size; ++index) {
            const uint8_t value = ary[index];

            if (lookup[value] > 0) {
                result[uniq_count++] = value;
                lookup[value] = 0;
            }
        }

        *res_size = uniq_count;

        return result;
    }

    return NULL;
}

int ary_has_dups(const uint8_t *ary, size_t size)
{
    if (!ary) return -1;

    uint8_t lookup[UINT8_MAX] = { 0 };

    for (size_t index = 0; index < size; ++index)
    {
        const uint8_t value = ary[index];
        ++lookup[value];

        if (lookup[value] > 1) return 0;
    }

    return 0;
}

int main(void)
{
    const uint8_t values[] = { 3, 7, 5, 5, 3, 4, 123, 4, 123, 8 };

    size_t   uniq_size = 0;
    uint8_t *uniq      = ary_uniq(values, sizeof(values) / sizeof(values[0]), &uniq_size);

    if (!uniq) return 1;

    for (size_t index = 0; index < uniq_size; ++index) {
        (void)printf(" %u", uniq[index]);
    }

    (void)putchar('\n');

    free(uniq); uniq = NULL;
    uniq_size = 0;

    (void)getchar();

    return 0;
}

