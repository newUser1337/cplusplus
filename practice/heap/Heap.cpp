#include <iostream>
#include <cstdlib>
#include <cstring>
#include "Heap.h"

template <class T>
HNode<T>::HNode()
{
}

template <class T>
HNode<T>::HNode(int in_index, T *in_data)
{
    index = in_index;
    data = in_data;
}

template <class T>
int HNode<T>::GetIndex()
{
    return index;
}

template <class T>
void HNode<T>::SetIndex(int in_index)
{
    index = in_index;
}

template <class T>
void HNode<T>::SetData(T *in_data)
{
    data = in_data;
}

template <class T>
T *HNode<T>::GetData()
{
    return data;
}

template <class T>
Heap<T>::Heap(int in_size)
{
    size = 0;
    bufsize = in_size * 2;
    Array = new HNode<T>[bufsize];
}

template <class T>
void Heap<T>::_SetElement(int pos)
{
    int left = _GetLeftPos(pos);
    int right = _GetRightPos(pos);
    int most = pos;
    if (left < size && Array[left].GetIndex() > Array[most].GetIndex())
        most = left;
    if (right < size && Array[right].GetIndex() > Array[most].GetIndex())
        most = right;
    if (most != pos)
    {
        _Swap(most, pos);
        _SetElement(most);
    }
}

template <class T>
void Heap<T>::_Swap(int a, int b)
{
    HNode<T> temp(Array[a].GetIndex(), Array[a].GetData());
    Array[a].SetIndex(Array[b].GetIndex());
    Array[a].SetData(Array[b].GetData());
    Array[b].SetIndex(temp.GetIndex());
    Array[b].SetData(temp.GetData());
}

template <class T>
int Heap<T>::_GetLeftPos(int pos)
{
    return pos * 2 + 1;
}

template <class T>
int Heap<T>::_GetRightPos(int pos)
{
    return pos * 2 + 2;
}

template <class T>
void Heap<T>::Print_index()
{
    for (int i = 0; i < size; i++)
        std::cout << Array[i].GetIndex() << " ";
    std::cout << std::endl;
}

template <class T>
void Heap<T>::AddElement(T *data, int index)
{
    _AllocMemory(size + 1);

    Array[size].SetData(data);
    Array[size].SetIndex(index);
    int pos = size++;

    while (pos > 0 && Array[(pos - 1) / 2].GetIndex() < Array[pos].GetIndex())
    {
        _Swap((pos - 1) / 2, pos);
        pos = (pos - 1) / 2;
    }
}

template <class T>
void Heap<T>::_AllocMemory(int reqsize)
{
    if (reqsize < bufsize)
        return;

    HNode<T> *temp = Array;
    bufsize *= 2;
    Array = new HNode<T>[bufsize];
    memcpy(Array, temp, size);
    delete[] temp;
}

template <class T>
HNode<T> Heap<T>::Pop()
{
    HNode<T> r_node = Array[0];
    size--;
    Array[0].SetIndex(Array[size].GetIndex());
    Array[0].SetData(Array[size].GetData());
    _SetElement(0);

    return r_node;
}