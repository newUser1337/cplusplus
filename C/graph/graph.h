#ifndef __GRAPH__
#define __GRAPH__

#include "list.h"
#include "tree.h"

typedef struct GNode
{
    List *list;
    int index;
    void *data;
} GNode;

typedef struct Graph
{
    Tree *tree;
    int size;
    void (*printdata)(void *);
    int (*cmpdata)(void *, void *);
} Graph;

Graph *graph_init(void (*)(void *), int (*)(void *, void *));
GNode *graph_add(Graph *, int, void *);
GNode *graph_find_by_ind(Graph *, int);
void graph_connect(Graph *, int, int);
void graph_print(Graph *);
void graph_dfs(Graph *, int);
void graph_bfs(Graph *, int);
void graph_dfs_rec(Graph *, int);

#endif