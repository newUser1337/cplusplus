#include <stdlib.h>
#include <stdio.h>
#include "list.h"

LNode *_list_node_create(void *);
void _list_node_destr(LNode **);

List *list_init(int (*cmpdata)(void *, void *), void (*printdata)(void *))
{
    List *list = (List *)malloc(sizeof(List));
    list->cmpdata = cmpdata;
    list->printdata = printdata;
    list->first = NULL;
    list->last = NULL;

    return list;
}

LNode *list_append(List *list, void *data)
{
    LNode *node = _list_node_create(data);
    if (list->last == NULL)
        list->first = node;
    else
        list->last->next = node;
    list->last = node;

    return node;
}

LNode *_list_node_create(void *data)
{
    LNode *node = (LNode *)malloc(sizeof(LNode));
    node->data = data;
    node->next = NULL;

    return node;
}

LNode *list_search(List *list, void *data)
{
    LNode *node = list->first;
    while (node != NULL && list->cmpdata(data, node->data))
        node = node->next;

    return node;
}

LNode *list_search_prev(List *list, void *data)
{
    LNode *node = list->first, *r_node = NULL;
    while (node != NULL && list->cmpdata(data, node->data))
    {
        r_node = node;
        node = node->next;
    }

    return r_node;
}

LNode *list_search_prev_sort(List *list, void *data)
{
    LNode *node = list->first, *r_node = NULL;
    while (node != NULL && list->cmpdata(data, node->data) != -1)
    {
        r_node = node;
        node = node->next;
    }

    return r_node;
}

LNode *list_insert(List *list, void *data)
{
    LNode *node = list_search(list, data);
    if (node != NULL)
        return node;

    node = _list_node_create(data);
    LNode *prev_node = list_search_prev_sort(list, data);

    if (prev_node != NULL)
    {
        node->next = prev_node->next;
        prev_node->next = node;
    }
    else
    {
        node->next = list->first;
        list->first = node;
    }
    if (node->next == NULL)
        list->last = node;

    return node;
}

void list_print(List *list)
{
    LNode *node = list->first;
    while (node != NULL)
    {
        list->printdata(node->data);
        node = node->next;
    }
    printf("\n");
}

void list_destr(List **list)
{
    LNode *node = (*list)->first, *temp;
    while (node != NULL)
    {
        temp = node->next;
        _list_node_destr(&node);
        node = temp;
    }
    free(*list);
    *list = NULL;
}

void _list_node_destr(LNode **node)
{
    free(*node);
    *node = NULL;
}

void list_remove(List *list, void *data)
{
    LNode *del_node, *prev_node;
    del_node = list_search(list, data);
    if (del_node == NULL)
        return; //node doesn't exist

    prev_node = list_search_prev(list, data);

    if (prev_node != NULL)
        prev_node->next = del_node->next;
    else
        list->first = del_node->next;

    if (del_node->next == NULL)
        list->last = prev_node;
    _list_node_destr(&del_node);
}
