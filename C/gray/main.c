#include "gray.h"

int main()
{
    Gray *gray = gray_init(3);

    while (gray_next(gray))
        gray_print(gray);

    return 0;
}