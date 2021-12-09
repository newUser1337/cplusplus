#include <stdlib.h>
#include <stdio.h>
#include "segment.h"

size_t _segment_get_left(size_t);
size_t _segment_get_right(size_t);
void _segment_set_telement(TElement *, int, size_t, size_t);
int _segment_fill_array(TElement *, size_t, int *, size_t, size_t);
int _segment_total(STree *, Range, size_t);

STree *segment_init(int *array, size_t size)
{
    STree *stree = (STree *)malloc(sizeof(STree));
    stree->tree_size = (size - 1) * 2 + 1;
    stree->array_size = size;
    stree->array = (TElement *)calloc(stree->tree_size, sizeof(TElement));
    _segment_fill_array(stree->array, 0, array, 0, size - 1);

    return stree;
}

int _segment_fill_array(TElement *t_arr, size_t t_id, int *array, size_t s_id, size_t e_id)
{
    if (s_id == e_id)
        _segment_set_telement(t_arr + t_id, array[s_id], s_id, s_id);
    else
    {
        size_t mid = (s_id + e_id) / 2;
        int val_l = _segment_fill_array(t_arr, _segment_get_left(t_id), array, s_id, mid);
        int val_r = _segment_fill_array(t_arr, _segment_get_right(t_id), array, mid + 1, e_id);

        _segment_set_telement(t_arr + t_id, val_l + val_r, s_id, e_id);
    }
    return t_arr[t_id].value;
}

size_t _segment_get_left(size_t index)
{
    return index * 2 + 1;
}

size_t _segment_get_right(size_t index)
{
    return index * 2 + 2;
}

void _segment_set_telement(TElement *element, int value, size_t low, size_t high)
{
    element->value = value;
    element->range.low = low;
    element->range.high = high;
}

void segment_print(STree *stree)
{
    for (size_t i = 0; i < stree->tree_size; i++)
        printf("%d ", stree->array[i].value);
    printf("\n");
}

int segment_total(STree *stree, Range range)
{
    int result;
    if (range.low > range.high || range.low < 0 || range.high > stree->array_size - 1)
        return 0;
    else
        return _segment_total(stree, range, 0);
}

int _segment_total(STree *stree, Range range, size_t index)
{
    if (range.low > stree->array[index].range.high ||
        range.high < stree->array[index].range.low)
        return 0;
    if (range.low <= stree->array[index].range.low &&
        range.high >= stree->array[index].range.high)
        return stree->array[index].value;

    return _segment_total(stree, range, _segment_get_left(index)) +
           _segment_total(stree, range, _segment_get_right(index));
}