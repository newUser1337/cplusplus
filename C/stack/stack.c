#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

Stack *stack_init(int size)
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->bufsize = size;
    stack->top = 0;
    stack->buf = (void **)malloc(sizeof(void *) * size);

    return stack;
}

void *stack_pop(Stack *st)
{
    if (!st->top)
        return NULL;
    return st->buf[--st->top];
}

void *stack_peek(Stack *st)
{
    if (!st->top)
        return NULL;
    return st->buf[st->top - 1];
}

void stack_push(Stack *st, void *data)
{
    if (st->top == st->bufsize)
        return;
    st->buf[st->top++] = data;
}

void stack_destr(Stack **st)
{
    free((*st)->buf);
    free(*st);
    *st = NULL;
}