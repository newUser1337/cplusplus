#include <stdlib.h>
#include <stdio.h>
#include "tree.h"
#include "disj.h"

void _dset_tree_print_index(void *);
int _dset_tree_cmp_index(void *, void *);

void _dset_destr_tree(Tree **);
void _dset_destr_tree_node_rec(TNode *);
void _dset_destr_tree_node(TNode **);

DNode *_dset_create_node(int, void *);

DSet *dset_init(void (*printdata)(DNode *))
{
    DSet *dset = (DSet *)malloc(sizeof(DSet));
    dset->printnode = printdata;
    dset->tree = tree_init(_dset_tree_print_index, _dset_tree_cmp_index);

    return dset;
}

void _dset_tree_print_index(void *data)
{
    DNode *node = data;
    printf("%d ", node->index);
}

int _dset_tree_cmp_index(void *data_1, void *data_2)
{
    DNode *dat_1 = data_1, *dat_2 = data_2;
    if (dat_1->index < dat_2->index)
        return -1;
    else if (dat_1->index > dat_2->index)
        return 1;
    else
        return 0;
}

DNode *dset_find_element_by_ind(DSet *dset, int index)
{
    DNode search, *result = NULL;
    search.index = index;
    TNode *temp = tree_find(dset->tree, &search);
    if (temp != NULL)
        result = temp->data;

    return result;
}

DNode *dset_find_set(DSet *dset, int index)
{
    DNode *result = dset_find_element_by_ind(dset, index);
    if (result == NULL)
        return NULL;
    while (result != result->parent)
        result = result->parent;
    return result;
}

DNode *dset_create_set(DSet *dset, int index, void *data)
{
    DNode *result = dset_find_element_by_ind(dset, index);
    if (result != NULL)
        return result;
    result = _dset_create_node(index, data);

    return (tree_add(dset->tree, result))->data;
}

DNode *_dset_create_node(int index, void *data)
{
    DNode *node = (DNode *)malloc(sizeof(DNode));
    node->data = data;
    node->index = index;
    node->rank = 0;
    node->parent = node;

    return node;
}

DNode *dset_join_set(DSet *dset, int index_1, int index_2)
{
    DNode *node_1 = dset_find_set(dset, index_1),
          *node_2 = dset_find_set(dset, index_2), *temp;
    if (node_1 == NULL || node_2 == NULL)
        return NULL;
    if (node_1 == node_2)
        return node_1;

    if (node_1->rank < node_2->rank)
    {
        temp = node_1;
        node_1 = node_2;
        node_2 = temp;
    }
    node_1->parent = node_2;
    node_2->rank++;

    return node_2;
}

void dset_print(DSet *dset, int index)
{
    DNode *node = dset_find_element_by_ind(dset, index);
    if (node == NULL)
        return;
    dset->printnode(node);
}

void dset_destr(DSet **dset)
{
    _dset_destr_tree(&(*dset)->tree);
    free(*dset);
    *dset = NULL;
}

void _dset_destr_tree(Tree **tree)
{
    _dset_destr_tree_node_rec((*tree)->root);
    free(*tree);
    *tree = NULL;
}

void _dset_destr_tree_node_rec(TNode *node)
{
    if (node == NULL)
        return;
    _dset_destr_tree_node_rec(node->left);
    _dset_destr_tree_node_rec(node->right);
    _dset_destr_tree_node(&node);
}
void _dset_destr_tree_node(TNode **node)
{
    free((*node)->data);
    free(*node);
    *node = NULL;
}
