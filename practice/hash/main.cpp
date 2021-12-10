#include <iostream>
#include "Hash.h"
#include "Hash.cpp"

int main()
{
    Hash<int> MM(100);
    int a = 1;
    int b = 2;
    int c = 3;
    int d = 4;
    MM.Add("one", &a);
    MM.Add("two", &b);
    MM.Add("three", &c);
    MM.Add("four", &d);

    std::cout << MM;
    return 0;
}