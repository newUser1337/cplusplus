#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

void print_ch(void *);
int cmp_ch(void *, void *);

int main()
{
    List *list = list_init(cmp_ch, print_ch);
    list_insert(list, "1");
    // list_insert(list, "Spb");
    list_insert(list, "3");
    // list_insert(list, "New-York");
    // list_insert(list, "Moscow");

    list_print(list);
    // list_remove(list, "New-York");
    // list_remove(list, "Moscow");
    list_print(list);
    list_insert(list, "2");
    list_print(list);

    list_destr(&list);
    return 0;
}

void print_ch(void *data)
{
    printf("%s ", (char *)data);
}

int cmp_ch(void *data_1, void *data_2)
{
    return strcmp((char *)data_1, (char *)data_2);
}