#include <stdio.h>
#include <stdlib.h>
#include "narr.h"

void _narr_swap(int *, int *);
void _narr_reverse(int *, int *);

Narr *narr_init(int size)
{
    Narr *narr = (Narr *)malloc(sizeof(Narr));
    narr->size = size;
    narr->count = 0;
    narr->mass = (int *)malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++)
        narr->mass[i] = i + 1;

    return narr;
}

void narr_destr(Narr **narr)
{
    free((*narr)->mass);
    free(*narr);
    *narr = NULL;
}

int narr_next(Narr *narr)
{
    if (!narr->count)
        return ++narr->count;

    int idi = -1, idj;

    for (int i = 0; i < narr->size - 1; i++)
        if (narr->mass[i] < narr->mass[i + 1])
            idi = i;

    if (idi == -1)
        return 0;

    for (int j = idi + 1; j < narr->size; j++)
        if (narr->mass[idi] < narr->mass[j])
            idj = j;

    _narr_swap(&narr->mass[idi], &narr->mass[idj]);
    _narr_reverse(narr->mass + idi + 1, narr->mass + narr->size - 1);
    return ++narr->count;
}

void _narr_swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void _narr_reverse(int *s, int *p)
{
    while (s < p)
        _narr_swap(s++, p--);
}

void narr_print(Narr *narr)
{
    printf("count %d ::", narr->count);
    for (int i = 0; i < narr->size; i++)
        printf("%d ", narr->mass[i]);
    printf("\n");
}