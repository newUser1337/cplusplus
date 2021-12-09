#include "narr.h"

int main()
{
    Narr *narr = narr_init(4);

    while (narr_next(narr))
        narr_print(narr);

    return 0;
}