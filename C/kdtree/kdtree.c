#include <stdlib.h>
#include <stdio.h>
#include "kdtree.h"
#include "list.h"

KDNode *_kdtree_add_rec(KDTree *, void *, int, KDNode *, KDNode *);
KDNode *_kdtree_node_create(void *);
void _kdtree_destr_node(KDNode **);
void _kdtree_destr_node_rec(KDNode *);
void _kdtree_print_preorder_rec(KDTree *, KDNode *);
KDNode *_kdtree_find_nearest(KDTree *, KDNode *, int, void *);
KDNode *_kdtree_closest(KDTree *, KDNode *, KDNode *, void *);
void _kdtree_find_range(KDTree *, KDNode *, void *, void *, int, List *);

KDTree *kdtree_init(int dimensions, void (*printdata)(void *), int (*cmpdata)(void *, void *, int), int (*dist)(void *, void *))
{
    KDTree *tree = (KDTree *)malloc(sizeof(KDTree));
    tree->root = NULL;
    tree->cmpdata = cmpdata;
    tree->dist = dist;
    tree->printdata = printdata;
    tree->K = dimensions;

    return tree;
}

KDNode *kdtree_add(KDTree *tree, void *data)
{
    return _kdtree_add_rec(tree, data, 0, tree->root, NULL);
}

KDNode *_kdtree_add_rec(KDTree *tree, void *data, int depth, KDNode *node, KDNode *parent)
{
    if (node == NULL)
    {
        node = _kdtree_node_create(data);
        node->parent = parent;
        if (parent == NULL)
            tree->root = node;
        else
        {
            if (tree->cmpdata(node->data, parent->data, (depth - 1) % tree->K) < 0)
                parent->left = node;
            else
                parent->right = node;
        }
    }
    else
    {
        if (tree->cmpdata(data, node->data, depth % tree->K) < 0)
            _kdtree_add_rec(tree, data, depth + 1, node->left, node);
        else
            _kdtree_add_rec(tree, data, depth + 1, node->right, node);
    }

    return node;
}

KDNode *_kdtree_node_create(void *data)
{
    KDNode *node = (KDNode *)malloc(sizeof(KDNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;

    return node;
}

void kdtree_destr(KDTree **tree)
{
    _kdtree_destr_node_rec((*tree)->root);
    free(*tree);
    *tree = NULL;
}

void _kdtree_destr_node_rec(KDNode *node)
{
    if (node == NULL)
        return;
    _kdtree_destr_node_rec(node->left);
    _kdtree_destr_node_rec(node->right);
    _kdtree_destr_node(&node);
}

void _kdtree_destr_node(KDNode **node)
{
    free(*node);
    *node = NULL;
}

void kdtree_print_preorder(KDTree *tree)
{
    printf("Preorder tree\n");
    _kdtree_print_preorder_rec(tree, tree->root);
    printf("end of tree \n");
}

void _kdtree_print_preorder_rec(KDTree *tree, KDNode *node)
{
    if (node == NULL)
        return;
    tree->printdata(node->data);
    _kdtree_print_preorder_rec(tree, node->left);
    _kdtree_print_preorder_rec(tree, node->right);
}

KDNode *kdtree_find_nearest(KDTree *tree, void *data)
{
    return _kdtree_find_nearest(tree, tree->root, 0, data);
}

KDNode *_kdtree_find_nearest(KDTree *tree, KDNode *node, int depth, void *data)
{
    if (node == NULL)
        return NULL;
    KDNode *next, *other, *temp, *best;
    if (tree->cmpdata(data, node->data, depth % tree->K) < 0)
    {
        next = node->left;
        other = node->right;
    }
    else
    {
        next = node->right;
        other = node->left;
    }
    temp = _kdtree_find_nearest(tree, next, depth + 1, data);
    best = _kdtree_closest(tree, temp, node, data);

    int radius = tree->dist(best->data, data);
    int dist = tree->cmpdata(node->data, data, depth % tree->K);
    if (radius >= dist * dist)
    {
        temp = _kdtree_find_nearest(tree, other, depth + 1, data);
        best = _kdtree_closest(tree, temp, node, data);
    }
    return best;
}

KDNode *_kdtree_closest(KDTree *tree, KDNode *n1, KDNode *n2, void *data)
{
    if (n1 == NULL)
        return n2;
    if (n2 == NULL)
        return n1;
    int dist_1 = tree->dist(n1->data, data);
    int dist_2 = tree->dist(n2->data, data);
    if (dist_1 < dist_2)
        return n1;
    else
        return n2;
}

void kdtree_find_range(KDTree *tree, void *data_min, void *data_max, List *result)
{
    _kdtree_find_range(tree, tree->root, data_min, data_max, 0, result);
}

void _kdtree_find_range(KDTree *tree, KDNode *node, void *data_min, void *data_max, int depth, List *result)
{
    if (node == NULL)
        return;

    if (tree->cmpdata(node->data, data_min, depth % tree->K) < 0)
        _kdtree_find_range(tree, node->right, data_min, data_max, depth + 1, result);
    else
    {
        if (tree->cmpdata(node->data, data_max, depth % tree->K) <= 0)
        {
            _kdtree_find_range(tree, node->right, data_min, data_max, depth + 1, result);
            if (tree->cmpdata(node->data, data_min, (depth + 1) % tree->K) >= 0 &&
                tree->cmpdata(node->data, data_max, (depth + 1) % tree->K) <= 0)
                list_append(result, node->data);
        }
        _kdtree_find_range(tree, node->left, data_min, data_max, depth + 1, result);
    }
}
