#include <stdlib.h>
#include <stdio.h>
#include "gray.h"

void _gray_add_one(Gray *);
void _gray_get_code(Gray *gray);

Gray *gray_init(int size)
{
    Gray *gray = (Gray *)malloc(sizeof(Gray));
    gray->size = size;
    gray->count = 0;
    gray->mask = (char *)calloc(size, sizeof(char));
    gray->code = (char *)calloc(size, sizeof(char));

    return gray;
}
int gray_next(Gray *gray)
{
    int finish = 1;
    if (!gray->count)
        return ++gray->count;

    for (int i = 0; i < gray->size; i++)
        if (!gray->mask[i])
            finish = 0;

    if (finish)
        return 0;
    _gray_add_one(gray);
    _gray_get_code(gray);
    return ++gray->count;
}

void _gray_add_one(Gray *gray)
{
    char *cp = gray->mask;
    do
    {
        *cp = (*cp) ? 0 : 1;
        if (*cp)
            break;
    } while (++cp != (gray->mask + gray->size));
}

void _gray_get_code(Gray *gray)
{
    for (int i = 0; i < gray->size - 1; i++)
        gray->code[i] = gray->mask[i] ^ gray->mask[i + 1];
    gray->code[gray->size - 1] = gray->mask[gray->size - 1];
}

void gray_print(Gray *gray)
{
    for (int i = 0; i < gray->size; i++)
        printf("%d ", gray->code[i]);
    printf("\n");
}