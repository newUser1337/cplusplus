#ifndef __ARRAY_CPP__
#define __ARRAY_CPP__


#include "../iterable/Iterable.h"

template <class T>
class ArrayList : public Iterable<T>
{
private:
    int size;
    int bufsize;
    int position;
    T *array;

public:
    ArrayList();
    ArrayList(int bufsize);
    ~ArrayList();
    void Next();
    T &Data();
    void Realloc();
    void Reset(int a = -1);
    void Add(const T &);
    void Print();
    bool HasNext();
};

#endif