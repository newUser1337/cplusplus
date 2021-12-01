#include <iostream>
#include "List.h"
#include "List.cpp"

int main()
{
    List<int> list1;

    list1.add(5);
    list1.add(6);
    list1.add(7);
    list1.add(8);
    list1.add(9);
    list1.add(10);
    list1.print();


    list1.remove(5);
    list1.remove(10);
    list1.remove(6);
    list1.remove(7);
    list1.remove(8);
    list1.remove(9);
    list1.add(10);
    list1.print();  

}