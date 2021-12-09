#include <cstdlib>
#include <iostream>
#include <list>
#include <algorithm>
#include "Disj.h"

template <class T>
DNode<T>::DNode(const int in_index, const T &in_data)
{
    index = in_index;
    data = in_data;
    rank = 0;
    parent = this;
}

template <class T>
DNode<T>::DNode(const int in_index)
{
    index = in_index;
    rank = 0;
    parent = this;
}

template <class T>
DNode<T>::~DNode()
{
}

template <class T>
int DNode<T>::IncRank()
{
    return ++rank;
}

template <class T>
int DNode<T>::GetRank()
{
    return rank;
}

template <class T>
void DNode<T>::SetParent(DNode<T> *in_parent)
{
    parent = in_parent;
}

template <class T>
DNode<T> *DNode<T>::GetParent()
{
    return parent;
}

template <class T>
int DNode<T>::GetIndex()
{
    return index;
}

template <class T>
T &DNode<T>::GetData()
{
    return data;
}

template <class T>
bool DNode<T>::operator<(const DNode<T> &node)
{
    return (index < node.index) ? true : false;
}

template <class T>
DNode<T> DNode<T>::operator=(const DNode<T> &node)
{
    rank = node.rank;
    data = node.data;
    parent = node.parent;
    index = node.index;

    return *this;
}

template <class T>
bool DNode<T>::operator>(const DNode<T> &node)
{
    return (index > node.index) ? true : false;
}

template <class T>
bool DNode<T>::operator==(const DNode<T> &node)
{
    return (index == node.index) ? true : false;
}

template <class T>
bool DNode<T>::operator!=(const DNode<T> &node)
{
    return (index != node.index) ? true : false;
}

template <class T>
bool DNode<T>::operator==(const int &in_index)
{
    return (index == in_index) ? true : false;
}

template <class T>
std::ostream &operator<<(std::ostream &s, DNode<T> &node)
{
    s << node.GetIndex() << " ";
    return s;
}

template <class T>
Disj<T>::Disj()
{
}

template <class T>
DNode<T> *Disj<T>::CreateNode(int in_index, const T &data)
{
    DNode<T> *node = new DNode<T>(in_index, data);
    if (node == NULL)
        std::cout << "Error memory allocation" << std::endl;
    return node;
}

template <class T>
DNode<T> *Disj<T>::Find(int in_index)
{
    DNode<T> *node = NULL;
    typename std::list<DNode<T> *>::iterator iter;
    for (iter = Set.begin(); iter != Set.end(); iter++)
        if (**iter == in_index)
            node = *iter;
    return node;
}

template <class T>
DNode<T> *Disj<T>::Add(int in_index, const T &data)
{
    DNode<T> *node = Find(in_index);
    if (node != NULL)
        return node;
    node = CreateNode(in_index, data);
    Set.push_front(node);
    return node;
}

template <class T>
std::ostream &operator<<(std::ostream &s, Disj<T> &disjset)
{
    std::list<DNode<T> *> *tempL = disjset.GetSet1();
    typename std::list<DNode<T> *>::iterator iter;
    for (iter = tempL->begin(); iter != tempL->end(); iter++)
        s << **iter;
    s << std::endl;
    return s;
}

template <class T>
std::list<DNode<T> *> *Disj<T>::GetSet1(void)
{
    return &this->Set;
}

template <class T>
Disj<T>::~Disj()
{
    typename std::list<DNode<T> *>::iterator iter;
    DNode<T> *temp;
    for (iter = Set.begin(); iter != Set.end(); iter++)
    {
        temp = *iter;
        delete temp;
    }
}

template <class T>
DNode<T> *Disj<T>::GetParentNode(DNode<T> *node)
{
    while (node != node->GetParent())
        node = node->GetParent();
    return node;
}

template <class T>
DNode<T> *Disj<T>::FindSet(int in_index)
{
    DNode<T> *node = Find(in_index);
    if (node == NULL)
        return NULL;
    return GetParentNode(node);
}

template <class T>
DNode<T> *Disj<T>::Join(int index_1, int index_2)
{
    DNode<T> *node_1 = FindSet(index_1);
    DNode<T> *node_2 = FindSet(index_2), *temp;
    if (node_1 == NULL || node_2 == NULL || node_1 == node_2)
    {
        std::cout << "Nodes already connected" << std::endl;
        return node_1;
    }
    if (node_1->GetRank() < node_2->GetRank())
    {
        temp = node_1;
        node_1 = node_2;
        node_2 = temp;
    }
    node_1->SetParent(node_2);
    node_2->IncRank();
    return node_2;
}