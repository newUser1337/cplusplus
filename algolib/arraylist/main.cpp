#include <cstdlib>
#include "ArrayList.h"
#include "ArrayList.cpp"

int main()
{
    ArrayList<int> arm(1);

    for (int i = 0; i < 32; i++)
        arm.Add(i + 100);

    arm.Print();

    Iterable<int> *abc = dynamic_cast<Iterable<int> *>(&arm);
    while(abc->HasNext())
    {
        abc->Next();
        std::cout << abc->Data()<<std::endl;
    }

    return 0;
}