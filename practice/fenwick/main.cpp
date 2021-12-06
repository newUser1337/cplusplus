#include <iostream>
#include "Fenwick.h"
// #include "Fenwick.cpp"

#define SZ 9

void print_arr(int *, int);

int main()
{
    int mass[SZ];
    for (int i = 0; i < SZ; i++)
        mass[i] = i + 1;
    print_arr(mass, SZ);

    Fenwick Fenw(mass, SZ);
    Fenw.Print();
    int sum = Fenw.GetSumRange(0, 8);
    std::cout << "sum " << sum << std::endl;
    int element = Fenw.GetElement(8);
    std::cout << "element " << element << std::endl;

    return 0;
}

void print_arr(int *array, int size)
{
    for (int i = 0; i < size; i++)
        std::cout << array[i] << " ";
    std::cout << std::endl;
}