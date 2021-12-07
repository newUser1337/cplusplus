#ifndef __QUEUE__
#define __QUEUE__

typedef struct Queue
{
    int bufsize;
    void **buf;
    int st;
    int end;
    int length;
} Queue;

Queue *queue_init(int);
void queue_free(Queue **);
void queue_push(Queue *, void *);
void *queue_pop(Queue *);
void *queue_peek(Queue*);
#endif