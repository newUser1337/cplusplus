#ifndef __KDTREE__
#define __KDTREE__

#include "list.h"

typedef struct KDNode
{
    struct KDNode *parent;
    struct KDNode *left;
    struct KDNode *right;
    void *data;
} KDNode;

typedef struct KDTree
{
    KDNode *root;
    int K;
    void (*printdata)(void *);
    int (*cmpdata)(void *, void *, int);
    int (*dist)(void *, void *);
} KDTree;

KDTree *kdtree_init(int, void (*)(void *), int (*)(void *, void *, int), int (*)(void *, void *));
KDNode *kdtree_add(KDTree *, void *);
void kdtree_destr(KDTree **);

void kdtree_print_preorder(KDTree *);
KDNode *kdtree_find_nearest(KDTree *, void *);
void kdtree_find_range(KDTree *,void *,void *,List*);
#endif