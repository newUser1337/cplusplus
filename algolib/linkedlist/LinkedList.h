#ifndef __LIST_CPP__
#define __LIST_CPP__

#include <cstdlib>
#include "../iterable/Iterable.h"

template <class T>
class Node
{
private:
    Node<T> *next;

public:
    T data;
    Node(const T &item, Node<T> *ptrnext = NULL);
    void InsertAfter(Node<T> *p);
    Node<T> *DeleteAfter();
    Node<T> *NextNode() const;
};

template <class T>
class LinkedList : public Iterable<T>
{
private:
    Node<T> *front, *rear;
    Node<T> *prevPtr, *currPtr;
    int size;
    int position;
    Node<T> *GetNode(const T &item, Node<T> *ptrNext);
    void FreeNode(Node<T> *p);
    void CopyList(const LinkedList<T> &L); //

public:
    LinkedList(); //
    LinkedList(const LinkedList<T> &L);
    ~LinkedList();
    LinkedList<T> &operator=(const LinkedList<T> &L);
    int ListSize() const; //
    int ListEmpty() const;

    void Reset(int pos = -1);     //
    void Next();                 //
    int EndOfList() const;       //
    int CurrentPosition() const; //

    void InsertFront(const T &item); //
    void InsertRear(const T &item);  //
    void InsertAt(const T &item);    //
    void InsertAfter(const T &item); //

    void DeleteFront(); //
    void DeleteAt();    //

    T &Data(); //

    void ClearList(); //

    void PrintList();

    bool HasNext();
};

#endif