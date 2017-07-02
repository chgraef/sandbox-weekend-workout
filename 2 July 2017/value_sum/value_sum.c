#include "value_sum.h"

#include <ctype.h>

static int s_strtoi(const char *str, const char **out_end_ptr);

int value_sum(const char *str)
{
    if (!str) return -1;

    const char *curchr = str;
    int         total  = 0;

    while (*curchr)
    {
        if (isdigit(*curchr) || *curchr == '-' && isdigit(curchr[1])) {
            const int curval = s_strtoi(curchr, &curchr);
            total += curval;
        } else {
            ++curchr;
        }
    }

    return total;
}

static int s_strtoi(const char *str, const char **out_end_ptr)
{
    if (!str) return 0;

    const char *curchr = str;
    int         value  = 0;
    int         is_neg = *curchr == '-' ? (++curchr, 1) : 0;

    if (is_neg && !isdigit(*curchr)) {
        if (out_end_ptr) *out_end_ptr = str; 
        return 0;
    }

    while (isdigit(*curchr)) 
    {
        value = 10 * value + *curchr - '0';
        ++curchr;
    }

    if (is_neg)       value *= -1;
    if (out_end_ptr) *out_end_ptr = curchr;

    return value;
}

