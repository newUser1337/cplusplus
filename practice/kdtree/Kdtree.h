#ifndef __KDTREE_CPP__
#define __KDTREE_CPP__


template <class T>
class KDNode
{
private:
    KDNode<T> *parent;
    KDNode<T> *left;
    KDNode<T> *right;
    T data;

public:
    KDNode(const T &);
    KDNode<T> *GetParent();
    KDNode<T> *GetLeft();
    KDNode<T> *GetRight();
    void SetParent(const KDNode<T> *);
    void SetLeft(const KDNode<T> *);
    void SetRight(const KDNode<T> *);
    T &GetData();
};

template <class T>
class KDTree
{
private:
    KDNode<T> *root;
    KDNode<T> *GetNode(const T &);    
public:
    KDTree();
    KDTree(T *);
};

#endif