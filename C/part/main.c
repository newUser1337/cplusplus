#include "part.h"

int main()
{
    Part *part = part_init(7);

    while (part_next(part))
        part_print(part);
    return 0;
}