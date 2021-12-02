#include <cstdlib>
#include <cstring>
#include <iostream>
#include "Hash.h"

template <class K, class T>
Hash<K, T>::Hash() : Hash(10)
{
}

template <class K, class T>
Hash<K, T>::Hash(int modsize)
{
    size = 0;
    position = -1;
    this->modsize = GetNewModsize(modsize);
    array = new Node[this->modsize];
    for (int i = 0; i < this->modsize; i++)
        array[i].key = NULL;
}

template <class K, class T>
Hash<K, T>::~Hash()
{
    delete[] array;
}

template <class K, class T>
void Hash<K, T>::Add(T data, K key)
{
    if ((float)(size + 1) / modsize > 0.25)
        Realloc();

    size++;
    int index = Hashvalue(key);
    while (array[index % modsize].key != NULL)
        index++;
    array[index % modsize].data = data;
    array[index % modsize].key = key;
}

template <class K, class T>
int Hash<K, T>::Hashvalue(K key)
{
    char *c_key = (char *)key;
    size_t len = strlen(c_key);
    int result = 0, pmul = 7, p = 1;
    for (size_t i = 0; i < len; i++)
    {
        result += c_key[i] * p;
        p *= pmul;
    }

    return result % modsize;
}

template <class K, class T>
void Hash<K, T>::Realloc()
{
    Node *temp = array;
    array = new Node[modsize * 2];

    for (int i = 0; i < modsize * 2; i++)
        array[i].key = NULL;
    int prev_modsize = modsize;
    modsize = GetNewModsize(modsize * 2);
    Rehash(array, temp, prev_modsize);

    delete[] temp;
}

template <class K, class T>
bool Hash<K, T>::HasNext()
{
    if (size == 0)
        return false;
    int i;
    for (i = position + 1; i < modsize; i++)
        if (array[i].key != NULL)
            break;

    return i < modsize ? 1 : 0;
}

template <class K, class T>
void Hash<K, T>::Next()
{
    int i;
    for (i = position + 1; i < modsize; i++)
        if (array[i].key != NULL)
            break;
    position = i;
}
template <class K, class T>
T &Hash<K, T>::Data()
{
    return array[position].data;
}

template <class K, class T>
int Hash<K, T>::GetNewModsize(int n)
{
    int PRIME = 8;
    unsigned long primes[PRIME] = {41, 103, 509, 997, 2767, 3727, 5737, 8863};

    for (int i = 0; i < PRIME; i++)
        if (n < primes[i])
            return primes[i];
    return n;
}

template <class K, class T>
void Hash<K, T>::Rehash(Node *dest, Node *src, int prev_modsize)
{
    for (int i = 0; i < prev_modsize; i++)
    {
        if (src[i].key != NULL)
        {
            int index = Hashvalue(src[i].key);
            while (dest[index % modsize].key != NULL)
                index++;
            dest[index % modsize].key = src[i].key;
            dest[index % modsize].data = src[i].data;
        }
    }
}

template <class K, class T>
void Hash<K, T>::Print()
{
    for (int i = 0; i < modsize; i++)
        if (array[i].key != NULL)
            std::cout << "index " << i << " data: " << array[i].data << " key: " << array[i].key << std::endl;
}

template <class K, class T>
T &Hash<K, T>::Search(K key, T data)
{
    int index = Hashvalue(key);
    while (array[index % modsize].key != NULL && array[index % modsize].data != data)
        index++;

    return array[index % modsize].data;
}

template <class K, class T>
void Hash<K, T>::Reset(int a)
{
    if (a < -1 || a > size - 1)
    {
        std::cerr << "Reset: incorrect position" << a << std::endl;
        return;
    }

    position = a;
}