#ifndef __SEGMENT__
#define __SEGMENT__

#include <cstdlib>
#include <iostream>

typedef struct Range
{
    size_t low;
    size_t high;
} Range;

template <class T>
class Element
{
public:
    Range range;
    T data;
    T max;
    T min;

    template <T>
    friend std::ostream &operator<<(std::ostream &, Element<T> &);
};

template <class T>
class Segment
{
private:
    size_t ArraySize;
    size_t TreeSize;
    Element<T> *TArray;
    Element<T> _FillSegment(T *, size_t, size_t, size_t);
    void _SetElement(Element<T> *, T, T, T, size_t, size_t);
    size_t _GetLeft(size_t);
    size_t _GetRight(size_t);
    void _GetTotal(Range, size_t, T *);
    T* _GetMax(Range, size_t);
    T* _GetMin(Range, size_t);

public:
    Segment(T *, size_t);
    ~Segment();
    Element<T> *_GetArray();
    size_t _GetSize();
    void GetTotal(Range, T *);
    void GetMax(Range, T *);
    void GetMin(Range, T *);

    template <T>
    friend std::ostream &operator<<(std::ostream &, Segment<T> &);
};

#endif