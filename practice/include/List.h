#ifndef __LIST_CPP_
#define __LIST_CPP_

template <class T>
class LNode
{
private:
    LNode<T> *next;
    T data;

public:
    LNode(const T &);
    LNode<T> *GetNext() const;
    void SetNext( LNode<T> *);
    T GetData();
};

template <class T>
class List
{
private:
    LNode<T> *first;
    LNode<T> *last;
    LNode<T> *GetNode(const T &);

public:
    List();
    ~List();
    LNode<T> *Append(const T &);
    LNode<T> *Search(const T &);
    LNode<T> *SearchPrev(const T &);
    LNode<T> *SearchPrevSort(const T &);
    LNode<T> *Insert(const T &);
    void Print() const;
    void Remove(const T &);
};

#endif