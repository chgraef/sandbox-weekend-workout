#include <stdlib.h>
#include <limits.h>
#include <stdio.h>

int sum(const int *values, size_t count);

int *int32_to_digits(int value, size_t *out_count);

int is_lucky_number(int value);

int main(void)
{
    const int min_candidate = 1000;
    const int max_candidate = 10 * min_candidate;

    for (int candidate = min_candidate; candidate < max_candidate; ++candidate) 
    {
        if (is_lucky_number(candidate)) {
            (void)printf(" %d", candidate);
        }
    }

    (void)getchar();
    return EXIT_SUCCESS;
}

int sum(const int *values, size_t count)
{
    int total = 0;

    for (size_t index = 0; index < count; ++index) {
        total += values[index];
    }

    return total;
}

int *int32_to_digits(int value, size_t *out_count)
{
    if (*out_count) out_count = 0;
	
    static const size_t BUFFER_SIZE = 16;

    int *digits = (int*)calloc(BUFFER_SIZE, sizeof(*digits));

    if (digits)
    {
        long long magn = value > 0 ? value : -((long long)value);
        size_t	 count = 0;
		
        do {
            digits[count++] = (int)(magn % 10);
            magn /= 10;
        } while (magn > 0);

        for (size_t left = 0, right = count; left + 1 < right; ++left, --right) 
        {
            const int temp    = digits[right - 1];
            digits[right - 1] = digits[left];
            digits[left]      = temp;
        }

        if (out_count) *out_count = count;
    }

    return digits;
}

int is_lucky_number(int value)
{
    size_t digit_count = 0;
    int	  *digits      = int32_to_digits(value, &digit_count);

    if (!digits) return -1;

    const int is_lucky = (sum(digits, 2) == sum(&digits[2], 2));

    free(digits); digits = NULL;

    return is_lucky;
}
