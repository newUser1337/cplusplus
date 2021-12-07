#ifndef __GRAY_CPP__
#define __GRAY_CPP__

class Gray
{
private:
    int size;
    int *mask;
    int *code;
    int count;
    void _AddOne();
    void _SetCode();

public:
    Gray(int);
    ~Gray();
    int Next();
    void Print();
};

#endif