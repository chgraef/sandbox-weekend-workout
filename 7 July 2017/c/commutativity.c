#include <stdio.h>

#define null_coalesce(x, y) _null_coalesce  ((void*)(x), (void*)(y))
#define or(x, y)            _commute_or     ((void*)(x), (void*)(y))
#define and(x, y)           _commute_and    ((void*)(x), (void*)(y))

void *_null_coalesce (void *left, void *right);
void *_commute_or    (void *left, void *right);
void *_commute_and   (void *left, void *right);

static void try_out_null_coalesce   (void);
static void try_out_or              (void);
static void try_out_and             (void);

int main(void)
{
    try_out_null_coalesce();
    (void)putchar('\n');

    try_out_or();
    (void)putchar('\n');

    try_out_and();
    (void)putchar('\n');

    (void)getchar();
    return 0;
}

static void try_out_null_coalesce(void)
{
    /* Case 1 */
    {
        const char *const str1 = "hello";
        const char *const str2 = NULL;

        (void)printf("%s ", (char*)null_coalesce(str1, str2));
    }

    /* Case 2 */
    {
        const char *const str1 = NULL;
        const char *const str2 = "world";

        (void)printf("%s", (char*)null_coalesce(str1, str2));
    }

    /* Case 2 */
    {
        const char *const str1 = "!";
        const char *const str2 = "?";

        (void)printf("%s\n", (char*)null_coalesce(str1, str2));
    }
}

static void try_out_or(void)
{
    /* Case 1 */
    {
        const int val1 = 3741;
        const int val2 = 0;

        (void)printf("%d\n", (int)or(val1, val2));
    }

    /* Case 2 */
    {
        const int val1 = 0;
        const int val2 = 3741;

        (void)printf("%d\n", (int)or(val1, val2));
    }

    /* Case 3 */
    {
        const int val1 = 3741;
        const int val2 = 391;

        (void)printf("%d\n", (int)or(val1, val2));
    }
}

static void try_out_and(void)
{
    /* Case 1 */
    {
        const int val1 = 391;
        const int val2 = 0;

        (void)printf("%d\n", (int)and(val1, val2));
    }

    /* Case 2 */
    {
        const int val1 = 0;
        const int val2 = 391;

        (void)printf("%d\n", (int)and(val1, val2));
    }

    /* Case 3 */
    {
        const int val1 = 3741;
        const int val2 = 391;

        (void)printf("%d\n", (int)and(val1, val2));
    }
}

void *_null_coalesce(void *left, void *right)
{
    return left? left : right;
}

void *_commute_or(void *left, void *right)
{
    if (left) return left;
    return right;
}

void *_commute_and(void *left, void *right)
{
    if (!left) return left;
    return right;
}

