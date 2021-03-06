/* По графу вывести отдельные компоненты - количество графов, 
и количество вершинв графе  */

#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

int cmp_data(void *, void *);
void print_data(void *);

int main()
{
    Graph *graph = graph_init(print_data, cmp_data);
    int arr[13] = {0};
    int opres;
    int arg = 0;
    int ind = 1;
    graph_add(graph, ind++, &arr[arg++]);
    graph_add(graph, ind++, &arr[arg++]);
    graph_add(graph, ind++, &arr[arg++]);
    graph_add(graph, ind++, &arr[arg++]);
    graph_add(graph, ind++, &arr[arg++]);
    graph_add(graph, ind++, &arr[arg++]);

    graph_connect_direct(graph, 1, 2);
    graph_connect_direct(graph, 1, 3);
    graph_connect_direct(graph, 2, 3);
    graph_connect_direct(graph, 4, 1);
    graph_connect_direct(graph, 6, 4);
    graph_connect_direct(graph, 5, 6);
    graph_connect_direct(graph, 4, 5);
    graph_print(graph);

    int res;
    List **path;
    path = (List **)malloc(sizeof(List *));
    res = graph_direct_cycle(graph, path);
    if (res)
        printf("true\n");
    else
        printf("false\n");
    list_print(*path);

    list_destr(path);
    return 0;
}

void print_data(void *data)
{
    GNode *node = data;
    printf("%d ", node->index);
}

int cmp_data(void *data_1, void *data_2)
{
    GNode *node_1 = data_1, *node_2 = data_2;
    int res;
    if (node_1->index < node_2->index)
        res = -1;
    else if (node_1->index > node_2->index)
        res = 1;
    else
        res = 0;
    return res;
}