#include <stdlib.h>
#include <stdio.h>
#include "heap.h"
#include "string.h"

void _heap_set_element(Heap *, int);
void _swap(NHeap *, NHeap *);
void _heap_add_new(Heap *, int);
void _heap_realloc_cpy_mem(Heap *);
void _heap_alloc_memory(Heap *, int);

Heap *heap_init(int size)
{
    Heap *heap = (Heap *)malloc(sizeof(Heap));
    heap->size = 0;
    heap->bufsize = size * 2;
    heap->array = (NHeap *)malloc(sizeof(NHeap) * heap->bufsize);

    return heap;
}

void heap_build(Heap *heap)
{
    for (int i = heap->size / 2; i > 0; i--)
        _heap_set_element(heap, i);
}

void _heap_set_element(Heap *heap, int pos)
{
    int left = heap_get_left(pos);
    int right = heap_get_right(pos);
    int most = pos;
    if (left < heap->size && heap->array[left].index > heap->array[most].index)
        most = left;
    if (right < heap->size && heap->array[right].index > heap->array[most].index)
        most = right;
    if (pos != most)
    {
        _swap(&heap->array[most], &heap->array[pos]);
        _heap_set_element(heap, most);
    }
}

void _swap(NHeap *a, NHeap *b)
{
    NHeap temp = *a;
    *a = *b;
    *b = temp;
}


void heap_print(Heap *heap)
{
    printf("Printing heap\n");
    for (int i = 0; i < heap->size; i++)
        printf("%d ", heap->array[i].index);
    printf("\n");
}

int heap_get_left(int index)
{
    return index * 2 + 1;
}
int heap_get_right(int index)
{
    return index * 2 + 2;
}
NHeap heap_add_element(Heap *heap, void *data, int index)
{
    _heap_alloc_memory(heap, heap->size + 1);
    heap->array[heap->size].index = index;
    heap->array[heap->size].data = data;
    _heap_add_new(heap, heap->size++);
}

void _heap_add_new(Heap *heap, int pos)
{
    while (pos > 0 && heap->array[(pos - 1) / 2].index < heap->array[pos].index)
    {
        _swap(&heap->array[(pos - 1) / 2], &heap->array[pos]);
        pos = (pos - 1) / 2;
    }
}

void _heap_alloc_memory(Heap *heap, int req_size)
{
    if (req_size < heap->bufsize)
        return;
    _heap_realloc_cpy_mem(heap);
}

void _heap_realloc_cpy_mem(Heap *heap)
{
    NHeap *temp = heap->array;
    heap->bufsize *= 2;
    heap->array = (NHeap *)malloc(sizeof(NHeap) * heap->bufsize);
    memcpy(heap->array, temp, heap->size);
    free(temp);
}

NHeap heap_pop(Heap *heap)
{
    NHeap r_node = heap->array[0];
    heap->array[0] = heap->array[--heap->size];
    _heap_set_element(heap, 0);

    return r_node;
}