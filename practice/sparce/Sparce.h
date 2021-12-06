#ifndef __SPARCE__
#define __SPARCE__

class Sparce
{
private:
    int *X;
    int **ST;
    int log;
    int _GetLog(int);
    void _FIllTable(int *);
    int _SetElement(int, int);
    int _GetMin(int, int);

public:
    Sparce(int *, int);
    ~Sparce();
    void Print();
    int Rmq(int, int);
};

#endif