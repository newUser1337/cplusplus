#include <iostream>
#include <cstdlib>
#include "List.h"

template <class T>
List<T>::List()
{
    first = NULL;
    last = NULL;
}

template <class T>
Lnode<T> *List<T>::add(T data)
{
    Lnode<T> *p = new Lnode<T>();
    p->data = data;

    if (last == NULL)
    {
        first = p;
    }
    else
        last->next = p;
    last = p;

    return p;
}

template <class T>
Lnode<T> *List<T>::find(T data)
{
    Lnode<T> *node = first;
    while (node != NULL && node->data != data)
        node = node->next;

    return node;
}

template <class T>
Lnode<T> *List<T>::insert(T data)
{
    Lnode<T> *node = find(data);
    if (node == NULL)
    {
        Lnode<T> *prev = find_prev(data);
        node = new Lnode<T>();
        node->data = data;
        if (prev != NULL)
        {
            node->next = prev->next;
            prev->next = node;
        }
        else
        {
            node->next = first;
            first = node;
        }
        if (node->next == NULL)
            last = node;
    }

    return node;
}

template <class T>
Lnode<T> *List<T>::find_prev(T data)
{
    Lnode<T> *res = NULL, *node = first;
    while (node != NULL && data >= node->data)
    {
        res = node;
        node = node->next;
    }

    return res;
}

template <class T>
Lnode<T> *List<T>::find_prev(Lnode<T> *fnode)
{
    Lnode<T> *node = first;

    if (fnode == node)
        return NULL;
    while (node != NULL && node->next != fnode)
        node = node->next;

    return node;
}

template <class T>
void List<T>::remove(Lnode<T> *node)
{
    Lnode<T> *prev;
    if (first == node)
    {
        first = prev->next;
        if (last == node)
            last = prev->next;
    }
    else
    {
        prev = find_prev(node);
        if (node->next == NULL)
        {
            last = prev;
            prev->next = NULL;
        }
        else
            prev->next = node->next;
    }

    delete node;
}

template <class T>
void List<T>::remove(T data)
{
    Lnode<T> *node = find(data);
    if (node != NULL)
        remove(node);
}

template <class T>
void List<T>::print()
{
    Lnode<T> *node = first;
    while (node != NULL)
    {
        std::cout << ' ' << node->data;
        node = node->next;
    }
    std::cout << std::endl;
}