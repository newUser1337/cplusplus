#include <stdlib.h>
#include <stdio.h>
#include "tree.h"

TNode *_tree_node_create(void *);
TNode *_tree_add(Tree *tree, void *, TNode *, TNode *);

void _tree_node_destr_rec(TNode *);
void _tree_node_destr(TNode **);

void _tree_print_preorder_rec(TNode *, Tree *);
void _tree_print_postorder_rec(TNode *, Tree *);
void _tree_print_inorder_rec(TNode *, Tree *);

int _tree_get_deep(Tree *, TNode *);

TNode *_tree_find_rec(Tree *, TNode *, void *);

TNode *_tree_find_max(TNode *);

Tree *tree_init(void (*printdata)(void *), int (*cmpdata)(void *, void *))
{
    Tree *tree = (Tree *)malloc(sizeof(Tree));
    tree->cmpdata = cmpdata;
    tree->printdata = printdata;
    tree->root = NULL;

    return tree;
}

TNode *tree_add(Tree *tree, void *data)
{
    TNode *r_node = _tree_add(tree, data, tree->root, NULL);
}

TNode *_tree_add(Tree *tree, void *data, TNode *node, TNode *parent_node)
{
    if (node == NULL)
    {
        node = _tree_node_create(data);
        node->parent = parent_node;
        if (parent_node == NULL)
            return tree->root = node;
        if (tree->cmpdata(data, parent_node->data) < 0)
            parent_node->left = node;
        else
            parent_node->right = node;
    }
    else
    {
        if (tree->cmpdata(data, node->data) < 0)
            node = _tree_add(tree, data, node->left, node);
        else
            node = _tree_add(tree, data, node->right, node);
    }
    return node;
}

TNode *_tree_node_create(void *data)
{
    TNode *node = (TNode *)malloc(sizeof(TNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;

    return node;
}

void tree_destr(Tree **tree)
{
    _tree_node_destr_rec((*tree)->root);
    free(*tree);
    *tree = NULL;
}

void _tree_node_destr_rec(TNode *node)
{
    if (node == NULL)
        return;
    _tree_node_destr_rec(node->left);
    _tree_node_destr_rec(node->right);

    _tree_node_destr(&node);
}

void _tree_node_destr(TNode **node)
{
    free(*node);
    *node = NULL;
}

void tree_print_preorder(Tree *tree)
{
    printf("Preorder Tree \n");
    _tree_print_preorder_rec(tree->root, tree);
    printf("End of Tree \n");
}

void _tree_print_preorder_rec(TNode *node, Tree *tree)
{
    if (node == NULL)
        return;
    tree->printdata(node->data);
    _tree_print_preorder_rec(node->left, tree);
    _tree_print_preorder_rec(node->right, tree);
}

void tree_print_postorder(Tree *tree)
{
    printf("Postorder Tree:\n");
    _tree_print_postorder_rec(tree->root, tree);
    printf("End of Tree:\n\n");
}

void _tree_print_postorder_rec(TNode *node, Tree *tree)
{
    if (node == NULL)
        return;
    _tree_print_postorder_rec(node->left, tree);
    _tree_print_postorder_rec(node->right, tree);
    tree->printdata(node->data);
}

void tree_print_inorder(Tree *tree)
{
    printf("Postorder Tree:\n");
    _tree_print_inorder_rec(tree->root, tree);
    printf("End of Tree:\n\n");
}

void _tree_print_inorder_rec(TNode *node, Tree *tree)
{
    if (node == NULL)
        return;
    _tree_print_inorder_rec(node->left, tree);
    tree->printdata(node->data);
    _tree_print_inorder_rec(node->right, tree);
}

TNode *tree_find_lowest_common_anc(Tree *tree, TNode *node_1, TNode *node_2)
{
    int diff = _tree_get_deep(tree, node_1) - _tree_get_deep(tree, node_2);

    if (diff < 0)
        while (diff++)
            node_2 = node_2->parent;
    else if (diff > 0)
        while (diff--)
            node_1 = node_1->parent;

    while (node_1 != NULL && node_1 != node_2)
    {
        node_1 = node_1->parent;
        node_2 = node_2->parent;
    }

    return node_1;
}

int _tree_get_deep(Tree *tree, TNode *node)
{
    int i = 0;
    while (node != NULL)
    {
        i++;
        node = node->parent;
    }

    return i;
}

TNode *tree_find(Tree *tree, void *data)
{
    return _tree_find_rec(tree, tree->root, data);
}

TNode *_tree_find_rec(Tree *tree, TNode *node, void *data)
{
    if (node == NULL)
    {
        printf("Data not found \n");
        return NULL;
    }
    TNode *r_node;
    int cmp = tree->cmpdata(data, node->data);
    if (!cmp)
        r_node = node;
    else
    {
        if (cmp < 0)
            r_node = _tree_find_rec(tree, node->left, data);
        else
            r_node = _tree_find_rec(tree, node->right, data);
    }

    return r_node;
}

void tree_remove(Tree *tree, void *data)
{
    TNode *del_node, *r_node;
    del_node = tree_find(tree, data);
    if (del_node == NULL)
    {
        printf("Node doesn't exist\n");
        return;
    }
    if (del_node->right == NULL)
        r_node = del_node->left;
    else if (del_node->left == NULL)
        r_node = del_node->right;
    else
    {
        r_node = _tree_find_max(del_node->left);
        if (r_node->parent == del_node)
            r_node->right = del_node->right;
        else
            r_node->parent->right = r_node->left;
    }

    if (r_node != NULL)
    {
        if (r_node != del_node->left)
            r_node->left = del_node->left;
        if (r_node != del_node->right)
            r_node->right = del_node->right;
    }
    if (del_node == tree->root)
        tree->root = r_node;
    else
    {
        if (tree->cmpdata(del_node->data, del_node->parent->data) < 0)
            del_node->parent->left = r_node;
        else
            del_node->parent->right = r_node;
    }
}

TNode *_tree_find_max(TNode *node)
{
    while (node->right != NULL)
        node = node->right;
    return node;
}