#include <stdlib.h>
#include "../inc/linkedlist.h"


static link head = NULL;

link link_make_node(const unsigned char item)
{
    link p = (link)malloc(sizeof *p );
    p->item = item;
    p->next = NULL;
    return p;
}

void link_free_node(link p)
{
    free(p);
}

link link_search(const unsigned char key)
{
    link p = head;
    for (p = head; p; p = p->next) {
        if (p->item == key)
            return p;
    }
    return NULL;
}

void link_insert(link p)
{
    p->next = head;
    head = p;
}


void link_delete(link p)
{
    link pre;
    if (p == head) {
        head = p->next;
        return;
    }
    for (pre = head; pre; pre = pre->next) {
        if (pre->next == p) {
            pre->next = p->next;
            return;
        }
    }
}

void link_traverse(void (*link_fun)(link))
{
    link p;
    for (p = head; p ; p = p->next) {
        link_fun(p);
    }

}

void link_destroy(void)
{
    link q,p = head;
    head = NULL;
    while (p) {
        q = p;
        p = p->next;
        link_free_node(q);
    }
}

void link_push(link p)
{
    link_insert(p);
}

link link_pop(void)
{
    if (head == NULL) {
        return NULL;
    } else {
        link p = head;
        head = head->next;
        return p;
    }
}




