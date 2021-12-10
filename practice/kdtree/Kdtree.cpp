#include <cstdlib>
#include <iostream>
#include <list>
#include "Kdtree.h"

template <class T>
KDNode<T>::KDNode(T *in_data, int dim)
{
    data = in_data;
    parent = NULL;
    left = NULL;
    right = NULL;
    K = dim;
}

template <class T>
KDNode<T> *KDNode<T>::GetParent()
{
    return parent;
}

template <class T>
int KDNode<T>::GetDim()
{
    return K;
}

template <class T>
std::ostream &operator<<(std::ostream &s, KDNode<T> &node)
{
    T *point = node.GetData();
    int K = node.GetDim();
    s << "(" << point[0];
    for (int i = 1; i < K; i++)
        s << ", " << point[i];
    s << ")" << std::endl;
    return s;
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
void KDNode<T>::SetParent(KDNode<T> *node)
{
    parent = node;
}

template <class T>
void KDNode<T>::SetLeft(KDNode<T> *node)
{
    left = node;
}

template <class T>
void KDNode<T>::SetRight(KDNode<T> *node)
{
    right = node;
}

template <class T>
T *KDNode<T>::GetData()
{
    return data;
}

template <class T>
KDTree<T>::~KDTree()
{
    _TreeDestr(root);
}

template <class T>
void KDTree<T>::_TreeDestr(KDNode<T> *node)
{
    if (node == NULL)
        return;
    _TreeDestr(node->GetLeft());
    _TreeDestr(node->GetRight());
    delete node;
}

template <class T>
KDNode<T> *KDTree<T>::GetNode(T *data)
{
    KDNode<T> *point = new KDNode<T>(data, K);
    return point;
}

template <class T>
T KDNode<T>::GetDist(T *point, int K)
{
    T result = GetProj(point, 0) * GetProj(point, 0);
    for (int i = 1; i < K; i++)
        result += GetProj(point, i) * GetProj(point, i);
    return result;
}

template <class T>
T KDNode<T>::GetProj(T *point, int dim)
{
    return point[dim] - data[dim];
}

template <class T>
void KDTree<T>::Add(T *data)
{
    _Add(data, root, NULL, 0);
}

template <class T>
void KDTree<T>::_Add(T *data, KDNode<T> *node, KDNode<T> *prev, int depth)
{
    if (node == NULL)
    {
        node = GetNode(data);
        node->SetParent(prev);
        if (prev == NULL)
            root = node;
        else
        {
            if (data[(depth - 1) % K] < (prev->GetData())[(depth - 1) % K])
                prev->SetLeft(node);
            else
                prev->SetRight(node);
        }
    }
    else
    {
        if (data[depth % K] < (node->GetData())[depth % K])
            _Add(data, node->GetLeft(), node, depth + 1);
        else
            _Add(data, node->GetRight(), node, depth + 1);
    }
}

template <class T>
KDNode<T> *KDTree<T>::FindNode(T *data)
{
    return _Find(data, root, 0);
}

template <class T>
KDNode<T> *KDTree<T>::_Find(T *data, KDNode<T> *node, int depth)
{
    if (node == NULL)
        return NULL;
    if (data[depth % K] < (node->GetData())[depth % K])
        node = _Find(data, node->GetLeft(), depth + 1);
    if (data[depth % K] > (node->GetData())[depth % K])
        node = _Find(data, node->GetRight(), depth + 1);
    else if (data[(depth + 1) % K] != (node->GetData())[(depth + 1) % K])
        node = _Find(data, node->GetRight(), depth + 1);
    return node;
}

template <class T>
KDNode<T> *KDTree<T>::FindNearest(T *data)
{
    return _FindNearest(data, root, 0);
}

template <class T>
KDNode<T> *KDTree<T>::_FindNearest(T *data, KDNode<T> *node, int depth)
{
    if (node == NULL)
        return NULL;
    KDNode<T> *next, *other, *temp, *best;
    if (data[depth % K] < (node->GetData())[depth % K])
    {
        next = node->GetLeft();
        other = node->GetRight();
    }
    else
    {
        other = node->GetLeft();
        next = node->GetRight();
    }
    temp = _FindNearest(data, next, depth + 1);
    best = _Closest(temp, node, data);

    T radius = best->GetDist(data, K);
    T dist = node->GetProj(data, depth % K);
    if (radius >= dist * dist)
    {
        temp = _FindNearest(data, next, other + 1);
        best = _Closest(temp, best, data);
    }
    return best;
}

template <class T>
KDNode<T> *KDTree<T>::_Closest(KDNode<T> *n1, KDNode<T> *n2, T *point)
{
    if (n1 == NULL || n2 == NULL)
        return (n1 == NULL) ? n2 : n1;
    T dist_1 = n1->GetDist(point, K);
    T dist_2 = n2->GetDist(point, K);

    return (dist_1 < dist_2) ? n1 : n2;
}

template <class T>
std::ostream &operator<<(std::ostream &s, KDTree<T> &tree)
{
    s << "Tree: " << std::endl;
    return tree.Print(s, tree.GetRoot());
}

template <class T>
std::ostream &KDTree<T>::Print(std::ostream &s, KDNode<T> *node)
{
    if (node == NULL)
        return s;
    s << *node;
    return Print(Print(s, node->GetLeft()), node->GetRight());
}

template <class T>
KDNode<T> *KDTree<T>::GetRoot()
{
    return root;
}

template <class T>
void KDTree<T>::FindRange(T *data_min, T *data_max, std::list<T *> *result)
{
    FindRange(root, 0, data_min, data_max, result);
}

template <class T>
void KDTree<T>::_FindRange(KDNode<T> *node, int depth, T *data_min, T *data_max, std::list<T *> *result)
{
    if (node == NULL)
        return;
    if (node->GetData()[depth % K] < data_min[depth % K])
        _FindRange(node->GetRight(), depth + 1, data_min, data_max, result);
    else
    {
        if (node->GetData()[depth % K] <= data_max[depth % K])
        {
            _FindRange(node->GetRight(), depth + 1, data_min, data_max, result);
            if (node->GetData()[(depth + 1) % K] <= data_max[(depth + 1) % K] &&
                node->GetData()[(depth + 1) % K] >= data_min[(depth + 1) % K])
                result->push_front(node->GetData());
        }
        _FindRange(node->GetLeft(), depth + 1, data_min, data_max, result);
    }
}