#include <stdio.h>
#include "../inc/linkedlist.h"

void print_item(link p)
{
    printf("%d\n", p->item);
}

int main(int argc, char const *argv[])
{
    link p = link_make_node(10);
    link_insert(p);
    p = link_make_node(5);
    link_insert(p);
    p = link_make_node(90);
    link_insert(p);
    p = link_make_node(5);
    link_insert(p);
    link_delete(p);
    link_free_node(p);
    link_traverse(print_item);
    link_destroy();



    return 0;
}
