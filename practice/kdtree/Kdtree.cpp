#include <cstdlib>
#include <iostream>
#include "Kdtree.h"

template <class T>
KDNode<T>::KDNode(const T &in_data)
{
    data = in_data;
    parent = NULL;
    left = NULL;
    right = NULL;
}

template <class T>
KDNode<T> *KDNode<T>::GetParent()
{
    return parent;
}

template <class T>
KDNode<T> *KDNode<T>::GetLeft()
{
    return left;
}

template <class T>
KDNode<T> *KDNode<T>::GetRight()
{
    return right;
}

template <class T>
void KDNode<T>::SetParent(const KDNode<T> *node)
{
    parent = node;
}

template <class T>
void KDNode<T>::SetLeft(const KDNode<T> *node)
{
    left = node;
}

template <class T>
void KDNode<T>::SetRight(const KDNode<T> *node)
{
    right = node;
}

template <class T>
T &KDNode<T>::GetData()
{
    return data;
}

template <class T>
KDTree<T>::KDTree()
{
    root = NULL;
}

template <class T>
KDTree<T>::KDTree(T *point)
{

    root = GetNode(*point);
    std::cout << root->GetData();
}

template <class T>
KDNode<T> *KDTree<T>::GetNode(const T &data)
{
    KDNode<T> *point = new KDNode<T>(data);
    return point;
}