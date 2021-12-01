#include <iostream>
#include "List.h"
#include "List.cpp"

int main()
{
    List<int> list1;
    List<float> list2;

    list1.add(5);
    list2.add(2.7);

    std::cout << list1.remove();
}