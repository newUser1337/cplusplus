#include <iostream>
#include "Perm.h"
// #include "Perm.cpp"

int main()
{
    Perm perm(4);
    while (perm.Next())
        std::cout << perm;

    return 0;
}