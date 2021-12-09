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

typedef struct Path
{
    int from;
    int to;
} Path;

Graph *graph_init(void (*)(void *), int (*)(void *, void *));
GNode *graph_add(Graph *, int, void *);
GNode *graph_find_by_ind(Graph *, int);
void graph_connect(Graph *, int, int);
void graph_print(Graph *);
void graph_dfs(Graph *, int);
void graph_bfs(Graph *, int);
void graph_dfs_rec(Graph *, int);
void graph_component(Graph *, List *);
int graph_cycle(Graph *, int);
void graph_destr(Graph **);

void graph_connect_direct(Graph *, int, int);
int graph_direct_cycle(Graph *, List **);

#endif