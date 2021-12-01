#include <iostream>
#include <stdlib.h>
#include "List.h"

template <class T>
List<T>::List()
{
    sentiel = new Lnode<T>();
    sentiel->next = sentiel;
}

template <class T>
void List<T>::add(T data)
{
    Lnode<T> *p;

    p = new Lnode<T>();
    p->data = data;
    p->next = sentiel->next;
    sentiel->next = p;
}

template <class T>
T List<T>::remove()
{
    T data;
    Lnode<T> *node;

    if (sentiel->next == sentiel)
    {
        std::cerr << "ERROR: 'remove' called with empty list.\n";
        exit(1);
    }

    node = sentiel->next;
    data = node->data;

    sentiel->next = node->next;
    delete node;

    return data;
}