#ifndef __PERM_CPP__
#define __PERM_CPP__

#include <iostream>

class Perm
{
private:
    int size;
    int count;
    int *Array;
    int *dir;
    int Direction(int);
    void Swap(int *, int *);

public:
    Perm(int);
    ~Perm();
    int Next();
    friend std::ostream &operator<<(std::ostream &, Perm &);
};

#endif