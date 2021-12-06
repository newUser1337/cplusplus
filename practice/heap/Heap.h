#ifndef __HEAP__
#define __HEAP__

template <class T>
struct HNode
{
private:
    int index;
    T *data;

public:
    HNode(int, T *);
    HNode();
    int GetIndex();
    T *GetData();
    void SetIndex(int);
    void SetData(T *);
};

template <class T>
class Heap
{
private:
    int size;
    int bufsize;
    HNode<T> *Array;

    void _SetElement(int);
    int _GetLeftPos(int);
    int _GetRightPos(int);
    void _Swap(int, int);
    void _AllocMemory(int);

public:
    Heap(int);
    void Print_index();
    void AddElement(T *, int);
    HNode<T> Pop();
};

#endif