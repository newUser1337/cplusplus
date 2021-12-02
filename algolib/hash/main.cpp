
#include <cstring>
#include "Hash.h"
#include "Hash.cpp"

int main()
{
    Hash<char *, char *> obj(20);
    // char *key_1 = new char[5];
    // strcpy(key_1, "zqwe");
    char key_1[5] = "zqwe";
    char key_2[5] = "zqwe";
    char key_3[5] = "car";
    char key_4[10] = "computer";
    char key_5[5] = "124";

    char data_1[15] = "yesterday";
    char data_2[15] = "monday";
    char data_3[15] = "Dallas";
    char data_4[15] = "Lakers";
    char data_5[15] = "Oklahoma";

    obj.Add(data_1, key_1 );
    obj.Add(data_2, key_2 );
    obj.Add(data_3, key_3 );
    obj.Add(data_4, key_4 );
    obj.Add(data_5, key_5 );
    obj.Print();

    Iterable<char *> *abc = dynamic_cast<Iterable<char *> *>(&obj);
    while (abc->HasNext())
    {
        abc->Next();
        std::cout << abc->Data() << std::endl;
    }

    return 0;
}
