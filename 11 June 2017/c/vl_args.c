#include <stdio.h>
#include <stdlib.h>

typedef int *varg_list_t;

void  vl_init(varg_list_t *pvlist, const void *start_after_arg);
void *vl_next(varg_list_t *pvlist);
void  vl_free(varg_list_t *pvlist);

void print_integers(int first_arg, ...);

int main(void)
{
    print_integers(1, 2, 3, 4, 5, 0);

    (void)getchar();

    return EXIT_SUCCESS;
}

void vl_init(varg_list_t *pvlist, const void *hook)
{
    if (!pvlist)  return;
    if (!*pvlist) return;
    if (!hook)    return;

    *pvlist = (int*)hook + 1;
}

void *vl_next(varg_list_t *pvlist)
{
    if (!pvlist)  return NULL;
    if (!*pvlist) return NULL;

    void *const result = *pvlist;
    ++*pvlist;

    return result;
}

void vl_free(varg_list_t *pvlist)
{
}

void print_integers(int first_arg, ...)
{
    varg_list_t vlist;
    int         value;

    vl_init(&vlist, &first_arg);

    (void)printf("%d", first_arg);

    while ((value = *(int*)vl_next(&vlist))) {
        (void)printf(" %d", value);
    }

    (void)putchar('\n');

    vl_free(&vlist);
}
