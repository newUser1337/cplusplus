#include "Tree.h"

template <class T>
TNode<T>::TNode(const T &in_data)
{
    data = in_data;
    parent = NULL;
    left = NULL;
    right = NULL;
}

template <class T>
TNode<T> *TNode<T>::GetParent()
{
    return parent;
}

template <class T>
TNode<T> *TNode<T>::GetLeft()
{
    return left;
}

template <class T>
TNode<T> *TNode<T>::GetRight()
{
    return right;
}

template <class T>
void TNode<T>::SetParent(const TNode<T> *node)
{
    parent = node;
}

template <class T>
void TNode<T>::SetRight(const TNode<T> *node)
{
    right = node;
}

template <class T>
void TNode<T>::SetLeft(const TNode<T> *node)
{
    left = node;
}