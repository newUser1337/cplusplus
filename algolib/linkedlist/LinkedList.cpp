#include <iostream>
#include <cstdlib>
#include "LinkedList.h"

template <class T>
LNode<T>::LNode(const T &item, LNode<T> *ptrnext) : data(item), next(ptrnext)
{
}

template <class T>
LNode<T> *LNode<T>::NextNode() const
{
    return next;
}

template <class T>
void LNode<T>::InsertAfter(LNode<T> *p)
{
    p->next = next;
    next = p;
}

template <class T>
LNode<T> *LNode<T>::DeleteAfter()
{
    LNode<T> *tempPtr = next;
    if (next == NULL)
        return NULL;

    next = tempPtr->next;

    return tempPtr;
}

template <class T>
LinkedList<T>::LinkedList() : front(NULL), rear(NULL), prevPtr(NULL), currPtr(NULL), size(0), position(-1)
{
}
template <class T>
void LinkedList<T>::CopyList(const LinkedList<T> &L)
{
    LNode<T> *p = L.front;
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
    LNode<T> *currPosition, *nextPosition;

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
    LNode<T> *newNode;
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
    LNode<T> *newNode, *currPtr = front;
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
    LNode<T> *p;

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
    LNode<T> *p = front;

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
void LinkedList<T>::FreeNode(LNode<T> *p)
{
    delete p;
}

template <class T>
void LinkedList<T>::PrintList()
{
    LNode<T> *currPtr = front;

    while (currPtr != NULL)
    {
        std::cout << currPtr->data << " ";
        currPtr = currPtr->NextNode();
    }
}

template <class T>
LNode<T> *LinkedList<T>::GetNode(const T &item, LNode<T> *nextPtr)
{
    LNode<T> *newNode;
    newNode = new LNode<T>(item, nextPtr);
    if (newNode == NULL)
    {
        std::cerr << "Error memory allocation" << std::endl;
        exit(1);
    }
    return newNode;
}