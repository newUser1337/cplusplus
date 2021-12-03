#include <iostream>
#include "Tree.h"
#include "Tree.cpp"

int main()
{
    Tree<int> tr;
    // int a[14] = {0, -50, -100, -25, -30, -10, 50, 25, 10, 5, 15, 30, 100, -20};
    int a[7] = {0, -50, 50, -100, -25, 25, 100};
    // int arg = 0;

    for (int agr = 0; agr < 6; agr++)
        tr.Add(a[agr]);

    tr.PrintPreorder();

    while (tr.HasNext())
    {
        tr.Next();
        std::cout << tr.Data() << std::endl;
    }

    return 0;
}