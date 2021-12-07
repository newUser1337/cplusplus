#include <cstdlib>
#include <iostream>
#include "Part.h"

Part::Part(int in_size)
{
    size = in_size;
    array = new int[size];
    for (int i = 0; i < size; i++)
        array[i] = 1;
    sp = array;
    ep = array + size - 1;
    count = 0;
}

Part::~Part()
{
    delete[] array;
}

void Part::Print()
{
    int *cp = sp;
    do
    {
        std::cout << *cp << " ";
    } while (cp++ != ep);
    std::cout << std::endl;
}

int Part::Next()
{
    if (!count)
        return ++count;
    if (sp == ep)
        return 0;
    int *fp = _FindSmall();
    _SetArr(fp);
    _SplitArr(fp + 1);
    return ++count;
}

int *Part::_FindSmall()
{
    int *cp = sp, *fp = sp;
    do
    {
        if (*fp > *cp)
            fp = cp;
    } while (++cp != ep);

    return fp;
}

void Part::_SetArr(int *fp)
{
    (*fp)++;
    (*ep)--;
}

void Part::_SplitArr(int *fp)
{
    int *cp = fp, total = 0;
    do
    {
        total += *cp;
        *cp = 0;
    } while (cp++ != ep);
    ep = fp + total - 1;
    while (total)
        *(fp + --total) = 1;
}