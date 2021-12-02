
#include <cstring>
#include "Hash.h"
#include "Hash.cpp"

int main()
{
    Hash<int*, int*> obj(20);
    int key_1 = 1;
    int key_2 = 4;
    int key_3 = 324;
    int key_4 = 444;
    int key_5 = 123;

    int data_1 = 44;
    int data_2 = 55;
    int data_3 = 66;
    int data_4 = 77;
    int data_5 = 88;

    obj.Add(&key_1, &data_1);
    obj.Add(&key_2, &data_2);
    obj.Add(&key_3, &data_3);
    obj.Add(&key_4, &data_4);
    obj.Add(&key_5, &data_5);
    obj.Print();

    Iterable<int* > *abc = dynamic_cast<Iterable<int*> *>(&obj);
    while (abc->HasNext())
    {
        abc->Next();
        std::cout << *abc->Data() << std::endl;
    }

    return 0;
}
