#include <stdio.h>
#include <string.h>
#include "queue.h"

typedef struct Book{
    int pagecount;
    char name[50];
} Book;

void printbook(void *);

int main()
{
    Queue *queue = queue_init(3);

    Book b1; 
    b1.pagecount = 20; 
    strcpy(b1.name, "Name1");

    Book b2; 
    b2.pagecount = 30; 
    strcpy(b2.name, "Name2");

    Book b3; 
    b3.pagecount = 40;
    strcpy(b3.name, "Name3");


    Book * cur;
    
    queue_push(queue, &b1);
    queue_push(queue, &b2);
    cur = queue_pop(queue);
    cur = queue_pop(queue);
    queue_push(queue, &b3);
    queue_push(queue, &b1);

    queue_free(&queue);
    return 0;
}


void printbook(void *b)
{
    Book *c = (Book*)b;
    printf("Pages %d, name: %s\n", c->pagecount, c->name);
}

// void print_book_queue(Queue *queue)
// {
//     Book * cur;
//     while((cur = (Book*)queue_dequeue(queue)) != NULL)
//         printbook(cur);
// }