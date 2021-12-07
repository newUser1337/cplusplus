#include <stdlib.h>
#include <stdio.h>
#include "part.h"

int *_part_find_small(Part *);
void _part_set_arr(Part *, int *);
void _part_split_arr(Part *, int *);

Part *part_init(int size)
{
    Part *part = (Part *)malloc(sizeof(Part));
    part->array = (int *)malloc(sizeof(int) * size);
    part->sp = part->array;
    part->ep = part->sp + size - 1;
    part->count = 0;
    part->size = size;
    for (int i = 0; i < size; i++)
        part->array[i] = 1;

    return part;
}

void part_destr(Part **part)
{
    free((*part)->array);
    free(*part);
    *part = NULL;
}

int part_next(Part *part)
{
    if (!part->count)
        return ++part->count;
    if (part->sp == part->ep)
        return 0;
    int *fp = _part_find_small(part);
    _part_set_arr(part, fp);
    _part_split_arr(part, fp + 1);
    return ++part->count;
}

int *_part_find_small(Part *part)
{
    int *fp = part->sp, *cp = part->sp;
    do
    {
        if (*fp > *cp)
            fp = cp;
    } while (++cp != part->ep);

    return fp;
}

void _part_set_arr(Part *part, int *fp)
{
    (*fp)++;
    (*part->ep)--;
}

void _part_split_arr(Part *part, int *fp)
{
    int *cp = fp, total = 0;
    do
    {
        total += *cp;
    } while (cp++ != part->ep);
    part->ep = fp + total - 1;

    while (total)
        *(fp + --total) = 1;
}

void part_print(Part *part)
{
    int *cp = part->sp;
    do
    {
        printf("%d ", *cp);
    } while (cp++ != part->ep);
    printf("\n");
}