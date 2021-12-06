#include "Heap.h"
#include "Heap.cpp"

int main()
{
    Heap<int> Hp(20);
    int a = 4,
        b = 3,
        c = 8,
        d = 10,
        e = 11,
        g = 5;
    Hp.AddElement(&a, a);
    Hp.AddElement(&b, b);
    Hp.AddElement(&c, c);
    Hp.AddElement(&d, d);
    Hp.AddElement(&e, e);
    Hp.AddElement(&g, g);
    Hp.Print_index();

    Hp.Print_index();
    Hp.Pop();
    Hp.Print_index();
    Hp.Pop();
    Hp.Print_index();

    return 0;
}