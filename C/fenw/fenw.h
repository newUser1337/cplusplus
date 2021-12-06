#ifndef __FENW__
#define __FENW__

typedef struct fenw
{
    int size;
    int *array;
} fenw;

fenw *fenw_init(int *, int);
void fenw_destr(fenw **);
void fenw_update(fenw *, int, int);
void fenw_print(fenw *);

int fenw_get_sum_lr(fenw *, int, int);
int fenw_get_element(fenw *, int);

#endif