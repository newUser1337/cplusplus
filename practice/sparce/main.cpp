#include <iostream>
#include "Sparce.h"
#define SIZE 17

int main()
{
    int array[SIZE] = {2, 6, -3, 5, -7, 2, -8, 3, -5,
                       -2, 11, -20, 4, -4, -6, -4, -21};
    Sparce Spar(array, SIZE);
    Spar.Print();

    int r = 16;
    int l = 1;
    int res = Spar.Rmq(r, l);
    std::cout << "res" << res << std::endl;

    return 0;
}