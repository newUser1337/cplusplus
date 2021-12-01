#include "List.h"
#include "List.cpp"

int main()
{
    LinkedList<int> L;
    int arra[10] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 0};
    for (int i = 0; i < 10; i++)
        L.InsertAfter(arra[i]);
    L.PrintList();
    int m =123;
    L.InsertAt(m);
    L.PrintList();
    return 0;
}
