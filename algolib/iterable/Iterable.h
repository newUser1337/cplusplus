#ifndef __ITER_CPP__
#define __ITER_CPP__

template <class T>
class Iterable
{
public:
    virtual void Next() = 0;
    virtual T &Data() = 0;
    virtual bool HasNext() = 0;
};

#endif