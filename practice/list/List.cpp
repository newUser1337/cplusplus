#include <iostream>
#include <cstdlib>
#include "List.h"

template <class T>
LNode<T>::LNode(const T &in_data)
{
    data = in_data;
}

template <class T>
LNode<T> *LNode<T>::GetNext() const
{
    return next;
}

template <class T>
void LNode<T>::SetNext( LNode<T> *node)
{
    next = node;
}

template <class T>
T LNode<T>::GetData()
{
    return data;
}

template <class T>
List<T>::List()
{
    first = NULL;
    last = NULL;
}

template <class T>
LNode<T> *List<T>::GetNode(const T &data)
{
    LNode<T> *node = new LNode<T>(data);
    node->SetNext(NULL);

    return node;
}

template <class T>
LNode<T> *List<T>::Append(const T &data)
{
    LNode<T> *node = GetNode(data);
    if (last == NULL)
        first = node;
    else
        last->SetNext(node);
    last = node;

    return node;
}

template <class T>
LNode<T> *List<T>::Search(const T &data)
{
    LNode<T> *node = first;
    while (node != NULL && node->GetData() != data)
        node = node->GetNext();
    return node;
}

template <class T>
LNode<T> *List<T>::SearchPrev(const T &data)
{
    LNode<T> *node = first, *prev = NULL;
    while (node != NULL && node->GetData() != data)
    {
        prev = node;
        node = node->GetNext();
    }

    return prev;
}

template <class T>
LNode<T> *List<T>::SearchPrevSort(const T &data)
{
    LNode<T> *node = first, *prev = NULL;
    while (node != NULL && node->GetData() < data)
    {
        prev = node;
        node = node->GetNext();
    }

    return prev;
}

template <class T>
LNode<T> *List<T>::Insert(const T &data)
{
    LNode<T> *node = Search(data);
    if (node != NULL)
        return node;
    node = GetNode(data);
    LNode<T> *prev = SearchPrevSort(data);
    if (prev != NULL)
    {
        node->SetNext(prev->GetNext());
        prev->SetNext(node);
    }
    else
    {
        node->SetNext(first);
        first = node;
    }
    if (node->GetNext() == NULL)
        last = node;

    return node;
}

template <class T>
void List<T>::Print() const
{
    LNode<T> *node = first;
    while (node != NULL)
    {
        std::cout << node->GetData() << " ";
        node = node->GetNext();
    }
    std::cout << std::endl;
}

template <class T>
List<T>::~List()
{
    LNode<T> *node = first, *temp;
    while (node != NULL)
    {
        temp = node->GetNext();
        delete node;
        node = temp;
    }
}

template <class T>
void List<T>::Remove(const T &data)
{
    LNode<T> *del_node, *prev_node;
    del_node = Search(data);
    if (del_node == NULL)
        return;
    prev_node = SearchPrev(data);
    if (prev_node == NULL)
        first = del_node->GetNext();
    else
        prev_node->SetNext(del_node->GetNext());
    if (del_node->GetNext() == NULL)
        last = prev_node;
    delete del_node;
}