#include <stdlib.h>
#include <stdio.h>
#include "fenw.h"

int _fenw_get_next(int);
int _fenw_get_parent(int);
int _fenw_get_sum(fenw *, int);

fenw *fenw_init(int *arr, int size)
{
    fenw *fw = (fenw *)malloc(sizeof(fenw));
    fw->size = size;
    fw->array = (int *)malloc(sizeof(int) * size);

    for (int i = 0; i < fw->size; i++)
        fenw_update(fw, i, arr[i]);

    return fw;
}

void fenw_update(fenw *fw, int pos, int value)
{
    while (pos < fw->size)
    {
        fw->array[pos] += value;
        pos = _fenw_get_next(pos + 1) - 1;
    }
}

void fenw_destr(fenw **fw)
{
    free((*fw)->array);
    free(*fw);
    *fw = NULL;
}

int _fenw_get_next(int pos)
{
    return pos + (pos & -pos);
}

int _fenw_get_parent(int pos)
{
    return pos - (pos & -pos);
}

void fenw_print(fenw *fw)
{
    printf("printing fenw\n");
    for (int i = 0; i < fw->size; i++)
        printf("%d ", fw->array[i]);
    printf("\n");
}

int fenw_get_sum_lr(fenw *fw, int left, int right)
{
    int sum = _fenw_get_sum(fw, right);
    int sub = _fenw_get_sum(fw, left - 1);
    return sum - sub;
}

int _fenw_get_sum(fenw *fw, int pos)
{
    int out = 0;
    if (pos > -1)
    {
        while (pos > 0)
        {
            out += fw->array[pos];
            pos = _fenw_get_parent(pos + 1) - 1;
        }
        out += fw->array[pos];
    }

    return out;
}

int fenw_get_element(fenw *fw, int pos)
{
    return fenw_get_sum_lr(fw, pos, pos);
}