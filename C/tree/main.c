#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

#define SIZE 9

void print_val(void *);
int cmp_val(void *, void *);
void add_data_to_tree(Tree *, int, int *);

int main()
{
    int array[SIZE] = {4, 6, -2, -3, 5, 3, 7, -9, 14};
    Tree *tree = tree_init(print_val, cmp_val);
    add_data_to_tree(tree, SIZE, array);

    tree_print_preorder(tree);

    tree_remove(tree, &array[5]);
    tree_print_preorder(tree);
    return 0;
}

void add_data_to_tree(Tree *tree, int size, int *array)
{
    for (int i = 0; i < size; i++)
        tree_add(tree, array + i);
}

void print_val(void *value)
{
    printf("%d \n", *((int *)value));
}
int cmp_val(void *v1, void *v2)
{
    return *((int *)v1) - *((int *)v2);
}
