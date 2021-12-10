#ifndef __HASH_CPP__
#define __HASH_CPP__

#include <iostream>
#include <string>
#include <cstdlib>

template <class T>
class HNode
{
private:
    std::string key;
    T *data;

public:
    HNode(std::string in_key, T *in_data) : key(in_key), data(in_data){};

    std::string GetKey();
    T *GetData();

    void SetKey(std::string);
    void SetData(T *);

    template <T>
    friend std::ostream &operator<<(std::ostream &, HNode<T> &);
};

template <class T>
class Hash
{
private:
    HNode<T> **Mass;
    int modsize;
    int size;
    int GetModsize(int);

    HNode<T> *CreateNode(std::string, T *);

    int Calchash(std::string);
    void Rehash();


public:
    Hash(int);
    ~Hash();
    HNode<T> *Add(std::string, T *);
    
    HNode<T> **GetHash();
    int GetSize();

    template <T>
    friend std::ostream &operator<<(std::ostream &, Hash<T> &);
};

#endif