#include <iostream>
#include <cstdlib>
#include "Gray.h"

Gray::Gray(int in_size)
{
    count = 0;
    size = in_size;
    mask = new int[size];
    code = new int[size];
    for (int i = 0; i < size; i++)
    {
        mask[i] = 0;
        code[i] = 0;
    }

}

Gray::~Gray()
{
    delete[] mask;
    delete[] code;
}

void Gray::Print()
{
    for (int i = 0; i < size; i++)
        std::cout << code[i] << " ";
    std::cout << std::endl;
}

int Gray::Next()
{
    int finish = 1;
    if (!count)
        return ++count;
    for (int i = 0; i < size; i++)
        if (!mask[i])
            finish = 0;
    if (finish)
        return 0;
    _AddOne();
    _SetCode();
    return ++count;
}

void Gray::_AddOne()
{
    int *cp = mask;
    do
    {
        *cp = *cp ? 0 : 1;
        if (*cp)
            break;
    } while (++cp != mask + size);
}

void Gray::_SetCode()
{
    for (int i = 0; i < size - 1; i++)
        code[i] = mask[i] ^ mask[i + 1];
    code[size - 1] = mask[size - 1];
}