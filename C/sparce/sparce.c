#include <stdio.h>
#include <stdlib.h>
#include "sparce.h"

int _sparce_get_log(int);
int _sparce_min(int, int);
int _sparce_set_elemet(int **, int, int);
void _sparce_fill_ST(Sparce *, int *);

Sparce *sparce_init(int *array, int size)
{
    Sparce *spar = (Sparce *)malloc(sizeof(Sparce));
    spar->log = _sparce_get_log(size);
    spar->ST = (int **)malloc(sizeof(int *) * spar->log);
    spar->X = (int *)malloc(sizeof(int) * spar->log);
    spar->X[0] = size;
    spar->ST[0] = (int *)malloc(sizeof(int) * spar->X[0]);

    for (int i = 1; i < spar->log; i++)
    {
        spar->X[i] = spar->X[i - 1] - (1 << (i - 1));
        spar->ST[i] = (int *)malloc(sizeof(int) * spar->X[i]);
    }
    _sparce_fill_ST(spar, array);

    return spar;
}

void _sparce_fill_ST(Sparce *spar, int *array)
{
    for (int i = 0; i < spar->X[0]; i++)
        spar->ST[0][i] = array[i];

    for (int j = 1; j < spar->log; j++)
        for (int i = 0; i < spar->X[j]; i++)
            spar->ST[j][i] = _sparce_set_elemet(spar->ST, j - 1, i);
}

int _sparce_set_elemet(int **ST, int log, int ix)
{
    return _sparce_min(ST[log][ix], ST[log][ix + (1 << log)]);
}

int _sparce_min(int a, int b)
{
    return (a < b) ? a : b;
}

int _sparce_get_log(int in)
{
    int i;
    for (i = 0; in; in >>= 1, i++)
        ;
    return i;
}

void sparce_print(Sparce *spar)
{
    for (int log = 0; log < spar->log; log++)
    {
        for (int index = 0; index < spar->X[log]; index++)
            printf("%3d ", spar->ST[log][index]);
        printf("\n");
    }
}

int sparce_rmq(Sparce *spar, int r, int l)
{
    if (!(r > l && spar->X[0] > r && l > -1))
        return 0;

    int log = _sparce_get_log(r - l) - 1;
    if (log)
        return _sparce_min(spar->ST[log][l], spar->ST[log][r - (1 << log) + 1]);
    else
        return spar->ST[log][l];
}

void sparce_destr(Sparce **spar)
{
    for (int i = 0; i < (*spar)->log; i++)
    {
        free((*spar)->ST[i]);
    }
    free((*spar)->X);
    free((*spar)->ST);
    free(*spar);
    *spar = NULL;
}