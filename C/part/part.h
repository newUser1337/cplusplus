#ifndef __PART__
#define __PART__

typedef struct Part
{
    int size;
    int *sp;
    int count;
    int *ep;
    int *array;
} Part;

Part *part_init(int);
int part_next(Part *);
void part_destr(Part **);
void part_print(Part *);

#endif