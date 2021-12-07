#include <stdlib.h>
#include <stdio.h>
#include "tree.h"
#include "list.h"
#include "graph.h"
#include "stack.h"
#include "queue.h"

GNode *_graph_create_node(Graph *, int, void *);

void _graph_print(Graph *, GNode *);
void _graph_print_rec(Graph *, TNode *);

void _graph_dfs(Graph *, GNode *, Stack *, int *);
void _graph_bfs(Graph *, GNode *, Queue *, int *);
void _graph_dfs_rec(Graph *, GNode *, int *);

Graph *graph_init(void (*printdata)(void *), int (*cmpdata)(void *, void *))
{
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->size = 0;
    graph->cmpdata = cmpdata;
    graph->printdata = printdata;
    graph->tree = tree_init(printdata, cmpdata);

    return graph;
}

GNode *graph_add(Graph *graph, int index, void *data)
{
    GNode search;
    search.index = index;
    TNode *tnode = tree_find(graph->tree, &search);
    if (tnode != NULL)
    {
        printf("Element already exist\n");
        return tnode->data;
    }

    GNode *node = _graph_create_node(graph, index, data);
    graph->size++;
    tree_add(graph->tree, node);

    return node;
}

GNode *_graph_create_node(Graph *graph, int index, void *data)
{
    GNode *node = (GNode *)malloc(sizeof(GNode));
    node->data = data;
    node->index = index;
    node->list = list_init(graph->cmpdata, graph->printdata);

    return node;
}

GNode *graph_find_by_ind(Graph *graph, int index)
{
    GNode node, *result = NULL;
    node.index = index;

    TNode *tnode = tree_find(graph->tree, &node);
    if (tnode != NULL)
        result = tnode->data;

    return result;
}

void graph_connect(Graph *graph, int index_1, int index_2)
{
    GNode *node_1 = graph_find_by_ind(graph, index_1);
    GNode *node_2 = graph_find_by_ind(graph, index_2);

    if (node_1 == NULL || node_2 == NULL || index_1 == index_2)
        return; // erorr during search or equal nodes

    if (list_search(node_1->list, node_2) != NULL)
        return; //already connected;
    list_insert(node_1->list, node_2);
    list_insert(node_2->list, node_1);
}

void graph_print(Graph *graph)
{
    _graph_print_rec(graph, graph->tree->root);
}
void _graph_print_rec(Graph *graph, TNode *node)
{
    if (node == NULL)
        return;
    _graph_print(graph, node->data);
    _graph_print_rec(graph, node->left);
    _graph_print_rec(graph, node->right);
}

void _graph_print(Graph *graph, GNode *node)
{
    printf("Node: ");
    graph->printdata(node);
    printf("\nConnected with :");
    list_print(node->list);
}

void graph_dfs(Graph *graph, int start_index)
{
    GNode *node = graph_find_by_ind(graph, start_index);
    if (node == NULL)
        return; // node doesn't found

    int isvisited[graph->size];
    for (int i = 0; i < graph->size; i++)
        isvisited[i] = 0;
    Stack *st = stack_init(graph->size);
    printf("dfs\n");
    _graph_dfs(graph, node, st, isvisited);
    stack_destr(&st);
    printf("\n");
}

void _graph_dfs(Graph *graph, GNode *node, Stack *st, int *isvisited)
{
    isvisited[node->index - 1] = 1;
    stack_push(st, node);
    while (stack_peek(st) != NULL)
    {
        node = stack_pop(st);
        graph->printdata(node);
        LNode *lnode = node->list->first;
        while (lnode != NULL)
        {
            if (!isvisited[((GNode *)lnode->data)->index - 1])
            {
                stack_push(st, lnode->data);
                isvisited[((GNode *)lnode->data)->index - 1] = 1;
            }
            lnode = lnode->next;
        }
    }
}

void graph_bfs(Graph *graph, int start_index)
{
    GNode *node = graph_find_by_ind(graph, start_index);
    if (node == NULL)
        return; // node doesn't found

    int isvisited[graph->size];
    for (int i = 0; i < graph->size; i++)
        isvisited[i] = 0;
    Queue *qu = queue_init(graph->size);
    printf("bfs\n");
    _graph_bfs(graph, node, qu, isvisited);
    queue_free(&qu);
    printf("\n");
}

void _graph_bfs(Graph *graph, GNode *node, Queue *qu, int *isvisited)
{
    isvisited[node->index - 1] = 1;
    queue_push(qu, node);
    while (queue_peek(qu) != NULL)
    {
        node = queue_pop(qu);
        graph->printdata(node);
        LNode *lnode = node->list->first;
        while (lnode != NULL)
        {
            if (!isvisited[((GNode *)lnode->data)->index - 1])
            {
                queue_push(qu, lnode->data);
                isvisited[((GNode *)lnode->data)->index - 1] = 1;
            }
            lnode = lnode->next;
        }
    }
}

void graph_dfs_rec(Graph *graph, int start_index)
{
    GNode *node = graph_find_by_ind(graph, start_index);
    if (node == NULL)
        return;
    int isvisited[graph->size];
    for (int i = 0; i < graph->size; i++)
        isvisited[i] = 0;
    printf("dfs rec\n");
    _graph_dfs_rec(graph, node, isvisited);
    printf("\n");
}

void _graph_dfs_rec(Graph *graph, GNode *node, int *isvisited)
{
    if (isvisited[node->index - 1])
        return;
    isvisited[node->index - 1] = 1;
    graph->printdata(node);

    LNode *lnode = node->list->first;
    while (lnode != NULL)
    {
        if (!isvisited[((GNode *)lnode->data)->index - 1])
            _graph_dfs_rec(graph, lnode->data, isvisited);
        lnode = lnode->next;
    }
}

void graph_get_component(Graph *graph, List *result)
{
    int isvisited[graph->size];
    for (int i = 0; i < graph->size; i++)
        isvisited[i] = 0;

    _graph_get_component_rec(graph, graph->tree->root, isvisited, result);
}

void _graph_get_component_rec(Graph *graph, TNode *root, int *isvisited, List *result)
{
    if (root == NULL)
        return;
    if (!isvisited[((GNode *)root->data)->index - 1])
    {
        isvisited[((GNode *)root->data)->index - 1] = 1;

        GNode *source = _graph_create_node(graph, ((GNode *)root->data)->index, ((GNode *)root->data)->data);
        LNode *cur_node = list_append(result, source);
        
        list_insert(((GNode *)cur_node->data)->list, source);
        LNode *node = ((GNode *)root->data)->list->first;
        _graph_get_component_rec_ver(graph, cur_node, node, isvisited);
        while (node != NULL)
        {
            if (!isvisited[((GNode *)node->data)->index - 1])
            {
                isvisited[((GNode *)node->data)->index - 1] = 1;
                list_insert(((GNode *)cur_node->data)->list, node->data);
            }
            node = node->next;
        }
    }
    _graph_get_component_rec(graph, root->left, isvisited, result);
    _graph_get_component_rec(graph, root->right, isvisited, result);
}

void _graph_get_component_rec_ver(Graph *graph, LNode *root, LNode *node, int *isvisited)
{
    while (node != NULL)
    {
        if (!isvisited[((GNode *)node->data)->index - 1])
        {
            isvisited[((GNode *)node->data)->index - 1] = 1;
            list_insert(((GNode *)root->data)->list, node->data);
            _graph_get_component_rec_ver(graph, root, ((GNode *)node->data)->list->first, isvisited);
        }
        node = node->next;
    }
}