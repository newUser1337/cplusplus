#ifndef __PART_CPP__
#define __PART_CPP__

class Part
{
private:
    int size;
    int *sp;
    int *ep;
    int count;
    int *array;

    int *_FindSmall();
    void _SetArr(int *);
    void _SplitArr(int *);

public:
    Part(int);
    ~Part();
    int Next();
    void Print();
};

#endif