#include <iostream>
#include <cstdlib>
#include "Segment.h"

template <class T>
Segment<T>::Segment(T *array, size_t array_size)
{
    TreeSize = (array_size - 1) * 2 + 1;
    TArray = new Element<T>[TreeSize];
    ArraySize = array_size;
    _FillSegment(array, 0, 0, ArraySize - 1);
}

template <class T>
Segment<T>::~Segment()
{
    delete[] TArray;
}

template <class T>
Element<T> Segment<T>::_FillSegment(T *array, size_t cur, size_t st, size_t ed)
{
    if (st == ed)
        _SetElement(TArray + cur, array[st], array[st], array[st], st, ed);
    else
    {
        size_t mid = (st + ed) / 2;
        Element<T> left = _FillSegment(array, _GetLeft(cur), st, mid);
        Element<T> right = _FillSegment(array, _GetRight(cur), mid + 1, ed);

        _SetElement(TArray + cur, left.data + right.data,
                    ((left.max > right.max) ? left.max : right.max),
                    ((left.min < right.min) ? left.min : right.min), st, ed);
    }
    return TArray[cur];
}

template <class T>
void Segment<T>::_SetElement(Element<T> *element, T data, T max, T min, size_t low, size_t high)
{
    element->data = data;
    element->max = max;
    element->min = min;
    element->range.low = low;
    element->range.high = high;
}

template <class T>
size_t Segment<T>::_GetLeft(size_t index)
{
    return index * 2 + 1;
}
template <class T>
size_t Segment<T>::_GetRight(size_t index)
{
    return index * 2 + 2;
}

template <class T>
Element<T> *Segment<T>::_GetArray()
{
    return TArray;
}

template <class T>
size_t Segment<T>::_GetSize()
{
    return TreeSize;
}

template <class T>
std::ostream &operator<<(std::ostream &s, Segment<T> &segment)
{
    Element<T> *arr = segment._GetArray();
    size_t size = segment._GetSize();
    for (size_t i = 0; i < size; i++)
        s << arr[i];
    s << std::endl;
    return s;
}

template <class T>
void Segment<T>::GetTotal(Range range, T *result)
{
    if (!(range.low > range.high || range.low < 0 || range.high > ArraySize - 1))
        _GetTotal(range, 0, result);
}

template <class T>
void Segment<T>::_GetTotal(Range range, size_t cur, T *result)
{
    if (range.low > TArray[cur].range.high ||
        range.high < TArray[cur].range.low)
        return;
    if (range.low <= TArray[cur].range.low &&
        range.high >= TArray[cur].range.high)
    {
        *result += TArray[cur].data;
        return;
    }
    _GetTotal(range, _GetLeft(cur), result);
    _GetTotal(range, _GetRight(cur), result);
    return;
}
template <class T>
std::ostream &operator<<(std::ostream &s, Element<T> &element)
{
    s << "total/elem: " << element.data << std::endl;
    s << "max: " << element.max << std::endl;
    s << "min: " << element.min << std::endl;
    s << "range: [" << element.range.low << ", " << element.range.high << "]" << std::endl;
    return s;
}

template <class T>
void Segment<T>::GetMax(Range range, T *result)
{
    if (!(range.low > range.high || range.low < 0 || range.high > ArraySize - 1))
        *result = *_GetMax(range, 0);
}

template <class T>
T *Segment<T>::_GetMax(Range range, size_t cur)
{
    if (range.low > TArray[cur].range.high ||
        range.high < TArray[cur].range.low)
        return NULL;
    if (range.low <= TArray[cur].range.low &&
        range.high >= TArray[cur].range.high)
    {
        return &TArray[cur].max;
    }
    T *res;
    T *left = _GetMax(range, _GetLeft(cur));
    T *right = _GetMax(range, _GetRight(cur));
    if (left != NULL && right != NULL)
        res = (*left > *right) ? left : right;
    else if (left == NULL)
        res = right;
    else
        res = left;

    return res;
}

template <class T>
void Segment<T>::GetMin(Range range, T *result)
{
    if (!(range.low > range.high || range.low < 0 || range.high > ArraySize - 1))
        *result = *_GetMin(range, 0);
}

template <class T>
T *Segment<T>::_GetMin(Range range, size_t cur)
{
    if (range.low > TArray[cur].range.high ||
        range.high < TArray[cur].range.low)
        return NULL;
    if (range.low <= TArray[cur].range.low &&
        range.high >= TArray[cur].range.high)
    {
        return &TArray[cur].min;
    }
    T *res;
    T *left = _GetMin(range, _GetLeft(cur));
    T *right = _GetMin(range, _GetRight(cur));
    if (left != NULL && right != NULL)
        res = (*left < *right) ? left : right;
    else if (left == NULL)
        res = right;
    else
        res = left;

    return res;
}