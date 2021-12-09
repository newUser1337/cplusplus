#ifndef __SEGMENT__
#define __SEGMENT__

#include <stdlib.h>

typedef struct Range
{
    size_t low;
    size_t high;
} Range;

typedef struct TElement
{
    int value;
    Range range;
} TElement;

typedef struct STree
{
    TElement *array;
    size_t tree_size;
    size_t array_size;
} STree;

STree *segment_init(int *, size_t);
void segment_print(STree *);
int segment_total(STree *, Range);

#endif