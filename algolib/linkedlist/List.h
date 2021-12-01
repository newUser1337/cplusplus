#ifndef __LIST_CPP__
#define __LIST_CPP__

template <class T>
class Lnode
{
public:
    T data;
    Lnode<T> *next;
};

template <class T>
class List
{
private:
    Lnode<T> *first;
    Lnode<T> *last;
    int size;
public:
    List();
    int get_size();
    Lnode<T> *add(T);
    Lnode<T> *find(T);
    Lnode<T> *insert(T);
    Lnode<T> *find_prev(T);
    Lnode<T> *find_prev(Lnode<T> *);
    void remove(Lnode<T> *);
    void remove(T);
    void print();
};

#endif
