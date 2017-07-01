#include <stdlib.h>
#include <stdio.h>

typedef int *varglist;

void varg_init(varglist *valist, int *after_arg);

int *varg_next(varglist *valist);

void varg_free(varglist *valist);

int sum(int count, ...);

int main(void)
{
    const int total = sum(4, 1, 2, 3, 5);

    (void)printf("%d\n", total);
    (void)getchar();

    return 0;
}

int sum(int count, ...)
{
    int total = 0;
    varglist vl; varg_init(&vl, &count);

    for (int i = 0; i < count; ++i) {
        const int *curarg = varg_next(&vl);
        if (!curarg) return -1;

        total += *curarg;
    }

    varg_free(&vl);

    return total;
}

void varg_init(varglist *valist, int *after_arg)
{
    if (!valist)     return;
    if (!*valist)    return;
    if (!after_arg)  return;

    *valist = &after_arg[1];
}

int *varg_next(varglist *valist)
{
    if (!valist)   return NULL;
    if (!*valist)  return NULL;

    return (*valist)++;
}

void varg_free(varglist *valist)
{
    if (!valist)   return;
    if (!*valist)  return;

    *valist = NULL;
}

