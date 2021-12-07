#include "List.h"
#include "List.cpp"

int main()
{
    int a = 1, c = 3, b = 2;

    List<int> link;
    link.Insert(a);
    link.Insert(c);
    link.Print();
    link.Insert(b);
    link.Print();
    link.Remove(a);
    link.Print();
    link.Remove(b);
    link.Print();
    link.Remove(c);
    link.Print();
    link.Append(a);
    link.Append(b);
    link.Print();
    link.Remove(b);
    link.Print();
    

    return 0;
}