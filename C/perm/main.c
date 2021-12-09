#include "perm.h"

int main()
{
    Perm *perm = perm_init(3);
    while (perm_next(perm))
        perm_print(perm);

    return 0;
}