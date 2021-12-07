#ifndef __DISJ__
#define __DISJ__

#include "tree.h"

typedef struct DNode
{
    struct DNode *parent;
    int index;
    int rank;
    void *data;
} DNode;

typedef struct DSet
{
    Tree *tree;
    void (*printnode)(DNode *);
} DSet;

DSet *dset_init(void (*)(DNode *));
DNode *dset_find_element_by_ind(DSet *, int);
DNode *dset_find_set(DSet *, int);
DNode *dset_create_set(DSet *, int, void *);
DNode *dset_join_set(DSet *, int, int);
void dset_print(DSet *, int);
void dset_destr(DSet **);

#endif