#include "Segment.h"
#include "Segment.cpp"
#define N 7

int main()
{
    int array[N] = {-1, 5, 3, -4, 7, 8, 9};
    Segment<int> seg(array, N);
    std::cout << seg;

    int M = 0;
    Range rg;
    rg.low = 0;
    rg.high = 1;
    seg.GetTotal(rg, &M);
    std::cout << M << std::endl;
    seg.GetMax(rg, &M);
    std::cout << M << std::endl;
    seg.GetMin(rg, &M);
    std::cout << M << std::endl;
    return 0;
}