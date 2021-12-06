#include <iostream>
#include "Sparce.h"

Sparce::Sparce(int *array, int size)
{
    log = _GetLog(size);

    X = new int[log];
    ST = new int *[log];

    X[0] = size;
    ST[0] = new int[X[0]];
    for (int i = 1; i < log; i++)
    {
        X[i] = X[i - 1] - (1 << (i - 1));
        ST[i] = new int[X[i]];
    }

    _FIllTable(array);
}

Sparce::~Sparce()
{
    for (int j = 0; j < log; j++)
        delete[] ST[j];
    delete[] ST;
    delete[] X;
}

void Sparce::_FIllTable(int *array)
{
    for (int i = 0; i < X[0]; i++)
        ST[0][i] = array[i];

    for (int j = 1; j < log; j++)
        for (int i = 0; i < X[j]; i++)
            ST[j][i] = _SetElement(j - 1, i);
}

int Sparce::_SetElement(int log, int ix)
{
    return _GetMin(ST[log][ix], ST[log][ix + (1 << log)]);
}

int Sparce::_GetMin(int a, int b)
{
    return (a < b) ? a : b;
}

int Sparce::_GetLog(int in)
{
    int i;
    for (i = 0; in; in >>= 1, i++)
        ;

    return i;
}

void Sparce::Print()
{
    for (int j = 0; j < log; j++)
    {
        for (int i = 0; i < X[j]; i++)
        {
            std::cout.width(3);
            std::cout << ST[j][i] << " ";
        }
        std::cout << std::endl;
    }
}

int Sparce::Rmq(int r, int l)
{
    if (!(r > l && X[0] > r && l > -1))
        return 0;

    int log = _GetLog(r - l) - 1;
    if (log)
        return _GetMin(ST[log][l], ST[log][r - (1 << log) + 1]);
    else
        return ST[log][l];
}