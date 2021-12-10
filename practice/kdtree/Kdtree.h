#ifndef __KDTREE_CPP__
#define __KDTREE_CPP__

template <class T>
class KDNode
{
private:
    KDNode<T> *parent;
    KDNode<T> *left;
    KDNode<T> *right;
    T *data;
    int K;

public:
    KDNode(T *, int);
    KDNode<T> *GetParent();
    KDNode<T> *GetLeft();
    KDNode<T> *GetRight();
    int GetDim();
    void SetParent(KDNode<T> *);
    void SetLeft(KDNode<T> *);
    void SetRight(KDNode<T> *);
    T *GetData();
    T GetDist(T *, int);
    T GetProj(T *, int);

    template <T>
    friend std::ostream &operator<<(std::ostream &, KDNode<T> &);
};

template <class T>
class KDTree
{
private:
    KDNode<T> *root;
    int K;
    KDNode<T> *GetNode(T *);
    KDNode<T> *_Find(T *, KDNode<T> *, int);
    void _Add(T *, KDNode<T> *, KDNode<T> *, int);
    void _TreeDestr(KDNode<T> *);

    KDNode<T> *_FindNearest(T *, KDNode<T> *, int);
    KDNode<T> *_Closest(KDNode<T> *, KDNode<T> *, T *);

public:
    KDTree(int iK) : K(iK) { root = NULL; };
    ~KDTree();

    void Add(T *);
    KDNode<T> *FindNode(T *);
    KDNode<T> *FindNearest(T *);
    KDNode<T> *GetRoot();

    template <T>
    friend std::ostream &operator<<(std::ostream &, KDTree<T> &);

    std::ostream &Print(std::ostream &, KDNode<T> *);
};

#endif