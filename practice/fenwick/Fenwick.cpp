#include <cstdlib>
#include <iostream>
#include "Fenwick.h"

Fenwick::Fenwick(int *in_array, int in_size)
{
    size = in_size;
    array = new int[size];

    for (int i = 0; i < size; i++)
        Update(i, in_array[i]);
}

Fenwick::~Fenwick()
{
    delete[] array;
}

void Fenwick::Update(int pos, int value)
{
    while (pos < size)
    {
        array[pos] += value;
        pos = _GetNext(pos + 1) - 1;
    }
}

int Fenwick::_GetNext(int pos)
{
    return pos + (pos & -pos);
}

int Fenwick::_GetParent(int pos)
{
    return pos - (pos & -pos);
}

void Fenwick::Print()
{
    for (int i = 0; i < size; i++)
        std::cout << array[i] << " ";
    std::cout << std::endl;
}

int Fenwick::GetSumRange(int left, int right)
{
    int sum = _getSum(right);
    int sub = _getSum(left - 1);
    return sum - sub;
}

int Fenwick::_getSum(int pos)
{
    int out = 0;
    if (pos > -1)
    {
        while (pos > 0)
        {
            out += array[pos];
            pos = _GetParent(pos + 1) - 1;
        }
        out += array[pos];
    }

    return out;
}

int Fenwick::GetElement(int pos)
{
    return GetSumRange(pos, pos);
}