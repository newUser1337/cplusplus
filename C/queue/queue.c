#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

Queue *queue_init(int size)
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->bufsize = size;
    queue->buf = (void **)malloc(sizeof(void *) * size);
    queue->end = 0;
    queue->st = 0;
    queue->length = 0;

    return queue;
}

void queue_free(Queue **queue)
{
    free((*queue)->buf);
    free(*queue);
    *queue = NULL;
}

void queue_push(Queue *queue, void *data)
{
    if (queue->st == queue->end && queue->length)
    {
        printf("Error\n");
        return;
    }
    queue->buf[queue->end++] = data;
    queue->end = queue->end % queue->bufsize;
    queue->length++;
}

void *queue_pop(Queue *queue)
{
    if (queue->st == queue->end && !queue->length)
        return NULL;

    void *tmp = queue->buf[queue->st++];
    queue->st = queue->st % queue->bufsize;
    queue->length--;
    return tmp;
}

void *queue_peek(Queue *queue)
{
    if (queue->st == queue->end && !queue->length)
        return NULL;
    return queue->buf[queue->st];
}
