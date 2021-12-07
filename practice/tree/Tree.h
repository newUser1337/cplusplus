#ifndef __TREE_CPP__
#define __TREE_CPP__

template <class T>
class TNode
{
private:
    TNode<T> *parent;
    TNode<T> *left;
    TNode<T> *right;
    T data;

public:
    TNode(const T &);
    void SetParent(const TNode<T>*);
    void SetLeft(const TNode<T>*);
    void SetRight(const TNode<T>*);
    TNode<T>* GetParent();
    TNode<T>* GetLeft();
    TNode<T>* GetRight();
};

#endif