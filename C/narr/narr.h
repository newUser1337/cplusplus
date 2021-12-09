#ifndef __NARR__
#define __NARR__

typedef struct Narr
{
    int size;
    int count;
    int *mass;
} Narr;

Narr *narr_init(int);
void narr_destr(Narr **);
int narr_next(Narr *);
void narr_print(Narr *);

#endif