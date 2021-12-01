// #include "../iterable/Iterable.h"
#include "LinkedList.h"
#include "LinkedList.cpp"

int main()
{
    LinkedList<int> l1;
    for (int i = 0; i < 10; i++)
        l1.InsertAfter(i + 100);
    l1.PrintList();
    std::cout << std::endl;
    
    l1.Reset(-1);
    while (l1.HasNext())
    {
        l1.Next();
        std::cout << l1.Data() << std::endl;
    }

    return 0;
}
