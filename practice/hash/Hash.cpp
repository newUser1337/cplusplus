#include <iostream>
#include <string>
#include <cstdlib>
#include "Hash.h"

template <class T>
std::string HNode<T>::GetKey()
{
    return key;
}

template <class T>
T *HNode<T>::GetData()
{
    return data;
}

template <class T>
void HNode<T>::SetKey(std::string in_key)
{
    key = in_key;
}

template <class T>
void HNode<T>::SetData(T *in_data)
{
    data = in_data;
}

template <class T>
Hash<T>::Hash(int in_modsize)
{
    modsize = GetModsize(in_modsize);
    Mass = new HNode<T> *[modsize];

    for (int i = 0; i < modsize; i++)
        this->Mass[i] = NULL;

    size = 0;
}

template <class T>
int Hash<T>::GetModsize(int in_modsize)
{
    unsigned long primes[8] = {41, 103, 509, 997, 2767, 3727, 5737, 8863};

    for (int i = 0; i < 8; i++)
        if (in_modsize < primes[i])
            return primes[i];
    return primes[8 - 1];
}

template <class T>
Hash<T>::~Hash()
{
    for (int i = 0; i < modsize; i++)
        if (Mass[i] != NULL)
            delete Mass[i];

    delete[] Mass;
}

template <class T>
HNode<T> *Hash<T>::Add(std::string in_key, T *in_data)
{
    size++;
    Rehash();
    HNode<T> *node = CreateNode(in_key, in_data);
    int pos = Calchash(in_key);
    while (Mass[pos % modsize] != NULL)
        pos++;
    Mass[pos % modsize] = node;
    return node;
}

template <class T>
HNode<T> *Hash<T>::CreateNode(std::string in_key, T *in_data)
{
    HNode<T> *node = new HNode<T>(in_key, in_data);
    return node;
}

template <class T>
int Hash<T>::Calchash(std::string key)
{
    std::string::iterator iter;
    int result = 0, p = 1, pmul = 7;
    for (iter = key.begin(); iter != key.end(); iter++)
    {
        result += *iter * p;
        p = p * pmul;
    }
    return result % modsize;
}

template <class T>
void Hash<T>::Rehash()
{
    float bound = (float)size * 100 / modsize;
    if (bound < 25.0)
        return;

    int temp_modsize = modsize;
    modsize = GetModsize(modsize * 2);

    HNode<T> **NewMass = new HNode<T> *[modsize];
    for (int i = 0; i < temp_modsize; i++)
    {
        if (Mass[i] != NULL)
        {
            int index = Calchash(Mass[i]->GetKey());
            while (NewMass[index % modsize] != NULL)
                index++;
            NewMass[index % modsize] = Mass[i];
        }
    }
    delete[] Mass;
    Mass = NewMass;
}

template <class T>
std::ostream &operator<<(std::ostream &s, HNode<T> &node)
{
    s << *(node.GetData()) << " ";
    return s;
}

template <class T>
std::ostream &operator<<(std::ostream &s, Hash<T> &hashset)
{
    HNode<T> **array = hashset.GetHash();
    int modsize = hashset.GetSize();
    s << "Hash " << std::endl;
    for (int i = 0; i < modsize; i++)
        if (array[i] != NULL)
            s << *array[i];
    s << std::endl;
    return s;
}

template <class T>
HNode<T> **Hash<T>::GetHash()
{
    return Mass;
}

template <class T>
int Hash<T>::GetSize()
{
    return modsize;
}