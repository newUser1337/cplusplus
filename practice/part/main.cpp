#include "Part.h"
// #include "Part.cpp"

int main()
{
    Part part(4);

    while (part.Next())
        part.Print();

    return 0;
}