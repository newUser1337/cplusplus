#ifndef __DISJ_CPP__
#define __DISJ_CPP__

#include <iostream>
#include <list>
#include <algorithm>

template <class T>
class DNode
{
private:
    int index;
    int rank;
    DNode<T> *parent;
    T data;

public:
    DNode(const int, const T &);
    DNode(const int);
    ~DNode();
    int IncRank();
    int GetRank();
    void SetParent(DNode<T> *);
    DNode<T> *GetParent();
    T &GetData();
    int GetIndex();

    bool operator<(const DNode<T> &);
    bool operator>(const DNode<T> &);
    bool operator==(const DNode<T> &);
    bool operator!=(const DNode<T> &);
    bool operator==(const int &);
    DNode<T> operator=(const DNode<T> &);

    template <T>
    friend std::ostream &operator<<(std::ostream &, DNode<T> &);
};

template <class T>
class Disj
{
private:
    DNode<T> *CreateNode(int, const T &);
    std::list<DNode<T> *> Set;

public:
    Disj();
    ~Disj();
    DNode<T> *Find(int);
    DNode<T> *Add(int, const T &);
    std::list<DNode<T> *> *GetSet1(void);
    DNode<T> *GetParentNode(DNode<T> *);
    DNode<T> *FindSet(int);
    DNode<T> *Join(int, int);

    template <T>
    friend std::ostream &operator<<(std::ostream &, Disj<T> &);
};

#endif