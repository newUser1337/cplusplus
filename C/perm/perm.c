#include <stdio.h>
#include <stdlib.h>
#include "perm.h"

void swap(int *, int *);
int _perm_direction(Perm *, int);

Perm *perm_init(int size)
{
    Perm *perm = (Perm *)malloc(sizeof(Perm));
    perm->count = 0;
    perm->size = size;
    perm->dir = (int *)malloc(sizeof(int) * size);
    perm->mass = (int *)malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++)
    {
        perm->dir[i] = 1;
        perm->mass[i] = i + 1;
    }

    return perm;
}

void perm_destr(Perm **perm)
{
    free((*perm)->dir);
    free((*perm)->mass);
    free(*perm);
    *perm = NULL;
}

int perm_next(Perm *perm)
{
    if (!perm->count)
        return ++perm->count;

    int id = -1;

    for (int i = 0; i < perm->size; i++)
        if ((_perm_direction(perm, i)) && ((id == -1) || (perm->mass[i] > perm->mass[id])))
            id = i;

    if (id == -1)
        return 0;

    for (int i = 0; i < perm->size; i++)
        perm->dir[i] = perm->mass[i] > perm->mass[id] ? !perm->dir[i] : perm->dir[i];

    int z = id + 1 - 2 * perm->dir[id];
    swap(&perm->mass[id], &perm->mass[z]);
    swap(&perm->dir[id], &perm->dir[z]);
    return ++perm->count;
}

int _perm_direction(Perm *perm, int i)
{
    int z = i + 1 - 2 * perm->dir[i];
    if (z > -1 && z < perm->size)
        return ((perm->mass[i] > perm->mass[z]) ? 1 : 0);
    return 0;
}

void swap(int *a1, int *a2)
{
    int temp;

    temp = *a1;
    *a1 = *a2;
    *a2 = temp;
}

void perm_print(Perm *perm)
{
    printf("count %d :: ", perm->count);
    for (int i = 0; i < perm->size; i++)
        printf("%d ", perm->mass[i]);
    printf("\n");
}