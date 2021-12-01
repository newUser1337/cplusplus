#include <cstdlib>
#include <iostream>
#include <cstring>
#include "ArrayList.h"

template <class T>
ArrayList<T>::ArrayList()
    : ArrayList(10)
{
}

template <class T>
ArrayList<T>::ArrayList(int bufsize)
{
    size = 0;
    position = -1;
    this->bufsize = bufsize;
    array = new T[bufsize];
}

template <class T>
ArrayList<T>::~ArrayList()
{
    delete[] array;
}

template <class T>
void ArrayList<T>::Next()
{
    position++;
}

template <class T>
T &ArrayList<T>::Data()
{
    return array[position];
}

template <class T>
void ArrayList<T>::Realloc()
{
    T *temp = array;
    array = new T[bufsize * 2];

    memcpy(array, temp, sizeof(T) * bufsize);

    bufsize = bufsize * 2;

    delete[] temp;
}

template <class T>
void ArrayList<T>::Reset(int a)
{
    if (a < -1 || a > size - 1)
    {
        std::cerr << "Reset: incorrect position" << a << std::endl;
        return;
    }

    position = a;
}

template <class T>
void ArrayList<T>::Add(const T &item)
{
    if (size + 1 == bufsize)
        Realloc();
    array[size++] = item;
}

template <class T>
void ArrayList<T>::Print()
{
    for (int i = 0; i < size; i++)
        std::cout << array[i] << ' ';
    std::cout << std::endl;
}

template <class T>
bool ArrayList<T>::HasNext()
{
    if (size == 0)
        return false;

    return position + 1 < size ? 1 : 0;
}