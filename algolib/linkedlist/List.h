#ifndef __LIST_CPP__
#define __LIST_CPP__


template <class T>
class Lnode
{
public:
    T data;
// private:
    Lnode<T> *next;
};

template <class T>
class List
{
private:
    Lnode<T> *sentiel;

public:
    int empty();
    void add(T);
    T remove();
    List();
};

#endif
