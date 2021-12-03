#include <cstdlib>
#include <iostream>
#include "Tree.h"

template <class T>
TNode<T>::TNode(const T &data) : TNode(data, NULL)
{
}

template <class T>
TNode<T>::TNode(const T &data, TNode<T> *par)
{
    parent = par;
    right = NULL;
    left = NULL;
    this->data = data;
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
TNode<T> *TNode<T>::GetParent()
{
    return parent;
}

template <class T>
T &TNode<T>::GetData()
{
    return data;
}

template <class T>
void TNode<T>::SetLeftNode(TNode<T> *left_node)
{
    left = left_node;
}

template <class T>
void TNode<T>::SetRightNode(TNode<T> *right_node)
{
    right = right_node;
}

template <class T>
Tree<T>::Tree()
{
    root = NULL;
    size = 0;
    currNode = NULL;
    prevNode = NULL;
    this->count = 0;
}

template <class T>
void Tree<T>::Add(const T &data)
{
    size++;
    if (root == NULL)
    {
        root = GetNode(data, NULL);
    }
    else
        AddData(data, root);
}

template <class T>
void Tree<T>::AddData(const T &data, TNode<T> *node)
{
    TNode<T> *newNode;
    if (data < node->GetData())
    {

        if (node->GetLeft() == NULL)
        {
            newNode = GetNode(data, node);
            node->SetLeftNode(newNode);
        }
        else
            AddData(data, node->GetLeft());
    }
    else
    {
        if (node->GetRight() == NULL)
        {
            newNode = GetNode(data, node);
            node->SetRightNode(newNode);
        }
        else
            AddData(data, node->GetRight());
    }
}

template <class T>
TNode<T> *Tree<T>::GetNode(const T &data, TNode<T> *par)
{
    TNode<T> *newNode;
    newNode = new TNode<T>(data, par);
    if (newNode == NULL)
    {
        std::cout << "Error memory allocation" << std::endl;
        exit(1);
    }

    return newNode;
}

template <class T>
void Tree<T>::PrintPreorder()
{
    std::cout << "Preorder Tree" << std::endl;
    PrintPreorderRec(root);
    std::cout << "End of tree" << std::endl;
}

template <class T>
void Tree<T>::PrintPreorderRec(TNode<T> *node)
{
    if (node == NULL)
        return;
    T data = node->GetData();
    std::cout << data << std::endl;
    PrintPreorderRec(node->GetLeft());
    PrintPreorderRec(node->GetRight());
}

template <class T>
void Tree<T>::Remove(const T &data)
{
    TNode<T> *del_node, *r_node;
    del_node = Find(data);
    if (del_node == NULL)
    {
        std::cout << "Node is not exist" << std::endl;
        return;
    }
    if (del_node->GetRight() == NULL)
        r_node = del_node->GetLeft();
    else if (del_node->GetLeft() == NULL)
        r_node = del_node->GetRight();
    else
    {
        r_node = FindMax(del_node->GetLeft());
        if (r_node->GetParent() == del_node)
            r_node->SetRightNode(del_node->GetRight());
        else
            (r_node->GetParent())->SetRightNode(r_node->GetLeft());
    }

    if (r_node == NULL)
        if (del_node == root)
            root = r_node;
        else
        {
            if (del_node->GetData() < del_node->GetParent()->GetData())
                del_node->GetParent()->SetLeftNode(NULL);
            else
                del_node->GetParent()->SetRightNode(NULL);
        }
    else
    {
        if (r_node != del_node->GetLeft())
            r_node->SetLeftNode(del_node->GetLeft());
        if (r_node != del_node->GetRight())
            r_node->SetRightNode(del_node->GetRight());
        if (del_node->GetParent() != NULL)
        {
            if (del_node->GetData() < (del_node->GetParent())->GetData())
                (del_node->GetParent())->SetLeftNode(r_node);
            else
                (del_node->GetParent())->SetRightNode(r_node);
        }
        else
            root = r_node;
    }

    size--;
}

template <class T>
TNode<T> *Tree<T>::Find(const T &data)
{
    return Find_rec(data, root);
}

template <class T>
TNode<T> *Tree<T>::Find_rec(const T &data, TNode<T> *node)
{
    if (node == NULL)
        return NULL;
    if (data < node->GetData())
        return Find_rec(data, node->GetLeft());
    else if (data > node->GetData())
        return Find_rec(data, node->GetRight());
    else
        return node;
}

template <class T>
TNode<T> *Tree<T>::FindMax(TNode<T> *node)
{
    if (node == NULL)
        return node;
    while (node->GetRight() != NULL)
        node = node->GetRight();
    return node;
}

template <class T>
T &Tree<T>::Data()
{
    return currNode->GetData();
}

template <class T>
void Tree<T>::Next()
{
    count++;
    NextRec();
}

template <class T>
void Tree<T>::NextRec()
{
    if (currNode == NULL)
        currNode = root;
    else
    {
        TNode<T> *temp = prevNode;
        prevNode = currNode;
        if (temp == currNode->GetRight() && temp != NULL)
        {
            currNode = currNode->GetParent();
            NextRec();
        }
        else if (temp == currNode->GetLeft() && temp != NULL)
        {
            if (currNode->GetRight() != NULL)
                currNode = currNode->GetRight();
            else
            {
                currNode = currNode->GetParent();
                NextRec();
            }
        }
        else if (temp == currNode->GetParent() || temp == NULL)
        {
            if (currNode->GetLeft() != NULL)
                currNode = currNode->GetLeft();
            else if (currNode->GetRight() != NULL)
                currNode = currNode->GetRight();
            else
            {
                currNode = currNode->GetParent();
                NextRec();
            }
        }
    }
}

template <class T>
bool Tree<T>::HasNext()
{
    if (count == size)
        return false;
    return true;
}

template <class T>
void Tree<T>::Reset()
{
    count = 0;
    currNode = NULL;
    prevNode = NULL;
}