#include <iostream>
#include "Disj.h"
#include "Disj.cpp"

int main()
{
    int m = 3;
    Disj<int> Collection;
    DNode<int> *n1, *n2;
    Collection.Add(1, m);
    Collection.Add(2, m);
    Collection.Add(3, m);
    Collection.Add(4, m);
    std::cout << Collection;
    Collection.Join(1, 2);
    Collection.Join(3, 4);

    return 0;
}
