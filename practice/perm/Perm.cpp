#include <iostream>
#include <cstdlib>
#include "Perm.h"

Perm::Perm(int in_size)
{
    size = in_size;
    count = 0;
    Array = new int[size];
    dir = new int[size];
    for (int i = 0; i < size; i++)
    {
        dir[i] = 1;
        Array[i] = i + 1;
    }
}

Perm::~Perm()
{
    delete[] dir;
    delete[] Array;
}

void Perm::Swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int Perm::Direction(int pos)
{
    int z = pos + 1 - 2 * dir[pos];
    if (z > -1 && z < size)
        return Array[pos] > Array[z] ? 1 : 0;
    return 0;
}

std::ostream &operator<<(std::ostream &s, Perm &perm)
{
    s << "count " << perm.count << " :: ";
    for (int i = 0; i < perm.size; i++)
        s << perm.Array[i] << " ";
    s << std::endl;
    return s;
}

int Perm::Next()
{
    if (!count)
        return ++count;
    int id = -1;
    for (int i = 0; i < size; i++)
        if (Direction(i) && ((id == -1) || Array[i] > Array[id]))
            id = i;
    if (id == -1)
        return 0;
    for (int i = 0; i < size; i++)
        dir[i] = Array[i] > Array[id] ? !dir[i] : dir[i];
    int pos = id + 1 - 2 * dir[id];
    Swap(Array + id, Array + pos);
    Swap(dir + id, dir + pos);
    return ++count;
}