#ifndef __STACK__
#define __STACK__

typedef struct Stack
{
    int top;
    void **buf;
    int bufsize;
} Stack;

Stack *stack_init(int);
void *stack_pop(Stack *);
void *stack_peek(Stack *);
void stack_push(Stack *, void *);
void stack_destr(Stack **);

#endif