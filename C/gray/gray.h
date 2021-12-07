#ifndef __GRAY__
#define __GRAY__

typedef struct Gray
{
    int size;
    int count;
    char *mask;
    char *code;
} Gray;

Gray *gray_init(int);
int gray_next(Gray *);
void gray_print(Gray *);

#endif