#ifndef __TREE_CPP_
#define __TREE_CPP_
#include "../iterable/Iterable.h"

template <class T>
class TNode
{
private:
    TNode<T> *left;
    TNode<T> *right;
    TNode<T> *parent;
    T data;

public:
    TNode(const T &, TNode<T> *);
    TNode(const T &);
    TNode<T> *GetLeft();
    TNode<T> *GetRight();
    TNode<T> *GetParent();
    void SetLeftNode(TNode<T> *);
    void SetRightNode(TNode<T> *);
    T &GetData();
};

template <class T>
class Tree : public Iterable<T>
{
private:
    TNode<T> *root;
    int size;
    TNode<T> *GetNode(const T &, TNode<T> *);
    void AddData(const T &, TNode<T> *);
    void PrintPreorderRec(TNode<T> *);
    TNode<T> *Find_rec(const T &, TNode<T> *);
    void Remove_rec();
    TNode<T> *FindMax(TNode<T> *);

    TNode<T> *currNode;
    TNode<T> *prevNode;
    int count;
    void NextRec();

public:
    Tree();
    void Add(const T &);
    void PrintPreorder();
    TNode<T> *Find(const T &);
    void Remove(const T &);
    void Reset();

    T &Data();
    bool HasNext();
    void Next();
};

#endif