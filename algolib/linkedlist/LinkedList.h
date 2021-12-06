#ifndef __LIST_CPP__
#define __LIST_CPP__

#include <cstdlib>
#include "../iterable/Iterable.h"

template <class T>
class LNode
{
private:
    LNode<T> *next;

public:
    T data;
    LNode(const T &item, LNode<T> *ptrnext = NULL);
    void InsertAfter(LNode<T> *p);
    LNode<T> *DeleteAfter();
    LNode<T> *NextNode() const;
};

template <class T>
class LinkedList : public Iterable<T>
{
private:
    LNode<T> *front, *rear;
    LNode<T> *prevPtr, *currPtr;
    int size;
    int position;
    LNode<T> *GetNode(const T &item, LNode<T> *ptrNext);
    void FreeNode(LNode<T> *p);
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