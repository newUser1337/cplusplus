#ifndef __HASH_CPP__
#define __HASH_CPP__

#include "../iterable/Iterable.h"

template <class K, class T>
class Hash : public Iterable<T>
{
    struct Node
    {
        K key;
        T data;
    };

private:
    int modsize;
    int size;
    Node *array;
    void Realloc();
    void Rehash(Node *,  Node *, int);
    int Hashvalue(K);
    int GetNewModsize(int);
    int position;

public:
    Hash();
    Hash(int modsize);
    ~Hash();
    void Add( T ,  K );
    void Print();
    T &Search( K ,  T );
    void Reset(int a = -1);

    void Next();
    T &Data();
    bool HasNext();
};

#endif