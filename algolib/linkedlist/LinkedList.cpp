#include <iostream>
#include <cstdlib>
#include "LinkedList.h"

template <class T>
Node<T>::Node(const T &item, Node<T> *ptrnext) : data(item), next(ptrnext)
{
}

template <class T>
Node<T> *Node<T>::NextNode() const
{
    return next;
}

template <class T>
void Node<T>::InsertAfter(Node<T> *p)
{
    p->next = next;
    next = p;
}

template <class T>
Node<T> *Node<T>::DeleteAfter()
{
    Node<T> *tempPtr = next;
    if (next == NULL)
        return NULL;

    next = tempPtr->next;

    return tempPtr;
}

// template <class T>
// Node<T> *GetNode(const T &item, Node<T> *nextPtr = NULL)
// {
//     Node<T> *newNode;
//     newNode = new Node<T>(item, nextPtr);
//     if (newNode == NULL)
//     {
//         std::cerr << "Error memory allocation" << std::endl;
//         exit(1);
//     }
//     return newNode;
// }

// template <class T>
// void InsertFront(Node<T> *&head, T item)
// {
//     head = GetNode(item, head);
// }

// template <class T>
// void PrintList(Node<T> *head)
// {
//     Node<T> *currPtr = head;

//     while (currPtr != NULL)
//     {
//         std::cout << currPtr->data << " ";
//         currPtr = currPtr->NextNode();
//     }
// }

// template <class T>
// void InsertRear(Node<T> *&head, const T &item)
// {
//     Node<T> *newNode, *currPtr = head;
//     if (currPtr == NULL)
//         InsertFront(head, item);
//     else
//     {
//         while (currPtr->nextNode() != NULL)
//             currPtr = currPtr->NextNode();
//         newNode = GetNode(item);
//         currPtr->InsertAfter(newNode);
//     }
// }

// template <class T>
// void DeleteFront(Node<T> *&head)
// {
//     Node<T> *p = head;

//     if (head != NULL)
//     {
//         head = head->NextNode();
//         delete p;
//     }
// }

// template <class T>
// void Delete(Node<T> *&head, T key)
// {
//     Node<T> *currPtr = head, *prevPtr = NULL;

//     if (currPtr == NULL)
//         return;
//     while (currPtr != NULL && currPtr->data != key)
//     {
//         prevPtr = currPtr;
//         currPtr = currPtr->NextNode();
//     }

//     if (currPtr != NULL)
//     {
//         if (prevPtr == NULL)
//             head = head->NextNode();
//         else
//             prevPtr->DeleteAfter();

//         delete currPtr;
//     }
// }

// template <class T>
// void InsertOrder(Node<T> *&head, T item)
// {
//     Node<T> *currPtr, *prevPtr, *newNode;

//     prevPtr = NULL;
//     currPtr = head;

//     while (currPtr != NULL)
//     {
//         if (item < currPtr->data)
//             break;

//         prevPtr = currPtr;
//         currPtr = currPtr->NextNode();
//     }

//     if (prevPtr == NULL)
//         InsertFront(head, item);
//     else
//     {
//         newNode = GetNode(item);
//         prevPtr->InsertAfter(newNode);
//     }
// }

// template <class T>
// void ClearList(Node<T> *&head)
// {
//     Node<T> *currPtr, *nextPtr;

//     currPtr = head;
//     while (currPtr != NULL)
//     {
//         nextPtr = currPtr->NextNode();
//         delete currPtr;
//         currPtr = nextPtr;
//     }
//     head = NULL;
// }

// template <class T>
// void LinkSort(T a[], int n)
// {
//     Node<T> *ordlist = NULL, *currPtr;
//     int i;

//     for (int i = 0; i < n; i++)
//         InsertOrder(ordlist, a[i]);

//     currPtr = ordlist;
//     i = 0;
//     while (currPtr != NULL)
//     {
//         a[i++] = currPtr->data;
//         currPtr = currPtr->NextNode();
//     }

//     ClearList(ordlist);
// }

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
template <class T>
LinkedList<T>::LinkedList() : front(NULL), rear(NULL), prevPtr(NULL), currPtr(NULL), size(0), position(-1)
{
}
template <class T>
void LinkedList<T>::CopyList(const LinkedList<T> &L)
{
    Node<T> *p = L.front;
    int pos;

    while (p != NULL)
    {
        InsertRear(p->data);
        p = p->NextNode();
    }

    if (position == -1)
        return;

    prevPtr = NULL;
    currPtr = front;
    for (pos = 0; pos != position; pos++)
    {
        prevPtr = currPtr;
        currPtr = currPtr->NextNode();
    }
}

template <class T>
void LinkedList<T>::ClearList()
{
    Node<T> *currPosition, *nextPosition;

    currPosition = front;
    while (currPosition != NULL)
    {
        nextPosition = currPosition->NextNode();
        FreeNode(currPosition);
        currPosition = nextPosition;
    }
    front = rear = NULL;
    prevPtr = currPtr = NULL;
    size = 0;
    position = -1;
}

template <class T>
void LinkedList<T>::Reset(int pos)
{
    int startPos;

    if (front == NULL)
        return;

    if (pos < -1 || pos > size - 1)
    {
        std::cerr << "Reset: incorrect position" << pos << std::endl;
        return;
    }

    if (pos == -1)
    {
        prevPtr = NULL;
        currPtr = NULL;
        position = -1;
    }
    else
    {
        currPtr = front->NextNode();
        prevPtr = front;
        startPos = 1;
        for (position = startPos; position != pos; position++)
        {
            prevPtr = currPtr;
            currPtr = currPtr->NextNode();
        }
    }
}

template <class T>
void LinkedList<T>::Next()
{
    if (position == -1)
    {
        currPtr = front;
        position++;
    }
    else if (currPtr != NULL)
    {
        prevPtr = currPtr;
        currPtr = currPtr->NextNode();
        position++;
    }
}
template <class T>
bool LinkedList<T>::HasNext()
{
    if (size == 0)
        return false;

    return position + 1 < size ? true : false;
}

template <class T>
T &LinkedList<T>::Data()
{
    if (size == 0 || currPtr == NULL)
    {
        std::cerr << "Data: incorrect pointer";
        exit(1);
    }
    return currPtr->data;
}

template <class T>
void LinkedList<T>::InsertAt(const T &item)
{
    Node<T> *newNode;
    if (prevPtr == NULL)
    {
        newNode = GetNode(item, front);
        front = newNode;
    }
    else
    {
        newNode = GetNode(item, NULL);
        prevPtr->InsertAfter(newNode);
    }
    if (prevPtr == rear)
    {
        rear = newNode;
        // position = size;
    }

    currPtr = newNode;
    size++;
}

template <class T>
void LinkedList<T>::InsertFront(const T &item)
{
    front = GetNode(item, front);
    size++;
}

template <class T>
void LinkedList<T>::InsertRear(const T &item)
{
    Node<T> *newNode, *currPtr = front;
    if (currPtr == NULL)
        InsertFront(item);
    else
    {
        while (currPtr->nextNode() != NULL)
            currPtr = currPtr->NextNode();
        newNode = GetNode(item);
        currPtr->InsertAfter(newNode);
    }
    size++;
}

template <class T>
void LinkedList<T>::InsertAfter(const T &item)
{
    Next();
    InsertAt(item);
}

template <class T>
void LinkedList<T>::DeleteAt()
{
    Node<T> *p;

    if (currPtr == NULL)
    {
        std::cerr << "Error delete" << std::endl;
        exit(1);
    }
    if (prevPtr == NULL)
    {
        p = front;
        front = front->NextNode();
    }
    else
        p = prevPtr->DeleteAfter();

    if (p == rear)
    {
        rear = prevPtr;
        // position--;
    }

    currPtr = p->NextNode();

    FreeNode(p);
    size--;
}

template <class T>
void LinkedList<T>::DeleteFront()
{
    Node<T> *p = front;

    if (front != NULL)
    {
        front = front->NextNode();
        delete p;
    }
}

template <class T>
int LinkedList<T>::ListSize() const
{
    return size;
}

template <class T>
int LinkedList<T>::CurrentPosition() const
{
    return position;
}

template <class T>
int LinkedList<T>::EndOfList() const
{
    if (currPtr == rear)
        return 1;
    return 0;
}

template <class T>
int LinkedList<T>::ListEmpty() const
{
    if (size == 0)
        return 1;
    return 0;
}

template <class T>
LinkedList<T>::~LinkedList()
{
    ClearList();
}

template <class T>
void LinkedList<T>::FreeNode(Node<T> *p)
{
    delete p;
}

template <class T>
void LinkedList<T>::PrintList()
{
    Node<T> *currPtr = front;

    while (currPtr != NULL)
    {
        std::cout << currPtr->data << " ";
        currPtr = currPtr->NextNode();
    }
}

template <class T>
Node<T> *LinkedList<T>::GetNode(const T &item, Node<T> *nextPtr)
{
    Node<T> *newNode;
    newNode = new Node<T>(item, nextPtr);
    if (newNode == NULL)
    {
        std::cerr << "Error memory allocation" << std::endl;
        exit(1);
    }
    return newNode;
}