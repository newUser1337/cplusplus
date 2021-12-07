#include "Gray.h"

int main()
{
    Gray gray(3);

    while (gray.Next())
        gray.Print();

    return 0;
}