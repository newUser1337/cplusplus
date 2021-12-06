#ifndef __HEAP__
#define __HEAP__

typedef struct NHeap
{
    int index;
    void *data;
} NHeap;

typedef struct Heap
{
    int size;
    int bufsize;
    NHeap *array;
} Heap;

Heap *heap_init(int);
void heap_destr(Heap **);
int heap_get_left(int);
int heap_get_right(int);
NHeap heap_add_element(Heap *, void *, int);
NHeap heap_pop(Heap *);
void heap_print(Heap *);
void heap_build(Heap *);

#endif