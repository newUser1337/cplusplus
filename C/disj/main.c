#include <stdio.h>
#include "disj.h"

#define N 7

void print_int(DNode *);
void init_array(int *, int);
void add_elements(DSet *, int *, int);

int main()
{
    int array[N] = {1, 2, 3, 4, 5, 6, 7};
    init_array(array, N);
    DSet *dsset = dset_init(print_int);
    add_elements(dsset, array, N);
    dset_join_set(dsset, 1, 2);
    dset_join_set(dsset, 3, 4);

    dset_join_set(dsset, 5, 6);
    dset_join_set(dsset, 5, 7);
    dset_join_set(dsset, 5, 4);

    print_int(dset_find_set(dsset, 6));
    printf("\n");
    print_int(dset_find_set(dsset, 7));
    printf("\n");

    return 0;
}

void print_int(DNode *node)
{
    printf("%d ", *((int *)node->data));
}

void init_array(int *array, int size)
{
    for (int i = 0; i < size; i++)
        array[i] = i;
}

void add_elements(DSet *dsset, int *array, int size)
{
    for (int i = 0; i < size; i++)
        dset_create_set(dsset, i + 1, &array[i]);

    printf("New elements\n");
    for (int i = 0; i < size; i++)
        dset_print(dsset, i + 1);
    printf("\n");
}
