#ifndef __FENWICK__
#define __FENWICK__

class Fenwick
{
private:
    int size;
    int *array;
    int _GetNext(int);
    int _GetParent(int);
    int _getSum(int);

public:
    Fenwick(int *, int);
    ~Fenwick();

    void Update(int, int);
    void Print();
    int GetSumRange(int, int);
    int GetElement(int);
};

#endif