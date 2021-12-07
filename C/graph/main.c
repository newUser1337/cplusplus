#include <stdio.h>
#include "tree.h"
#include "graph.h"

#define N 8

int cmp_data(void *, void *);
void printdata(void *);

int main()
{
    Graph *gr = graph_init(printdata, cmp_data);
    int arr[N] = {0};
    for (int i = 0; i < N; i++)
        graph_add(gr, i + 1, &arr[i]);
    graph_connect(gr, 2, 1);
    graph_connect(gr, 2, 3);
    graph_connect(gr, 2, 4);
    graph_connect(gr, 1, 7);
    graph_connect(gr, 3, 6);
    graph_connect(gr, 3, 4);
    graph_connect(gr, 5, 6);
    graph_connect(gr, 5, 4);
    graph_connect(gr, 5, 8);

    graph_print(gr);

    graph_dfs(gr, 3);
    graph_bfs(gr, 3);
    graph_dfs_rec(gr, 3);
    return 0;
}

int cmp_data(void *data_1, void *data_2)
{
    GNode *dat_1 = data_1, *dat_2 = data_2;
    if (dat_1->index < dat_2->index)
        return -1;
    else if (dat_1->index > dat_2->index)
        return 1;
    else
        return 0;
}

void printdata(void *data)
{
    GNode *node = data;
    printf("%d ", node->index);
}