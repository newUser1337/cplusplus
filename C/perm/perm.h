#ifndef __PERM__
#define __PERM__

typedef struct Perm
{
    int size;
    int count;
    int *mass;
    int *dir;
} Perm;

Perm *perm_init(int);
void perm_destr(Perm **);
int perm_next(Perm *);
void perm_print(Perm *);

#endif