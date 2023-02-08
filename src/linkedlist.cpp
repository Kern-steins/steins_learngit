#include <stdlib.h>
#include "../inc/linkedlist.h"

struct node sential = { 0, &sential, &sential};

static link head = &sential;


link link_make_node(const unsigned char item)
{
    link p = (link)malloc(sizeof *p );
    p->item = item;
    p->next = NULL;
    p->pre_v = NULL;
    return p;
}

void link_free_node(link p)
{
    free(p);
}

link link_search(const unsigned char key)
{
    link p = head;
    for (p = head->next; p != head; p = p->next) {
        if (p->item == key)
            return p;
    }
    return NULL;
}

void link_insert(link p)
{
    p->next = head->next;
    head->next->pre_v = p;
    head->next = p;
    p->pre_v = head;
}


void link_delete(link p)
{

    p->pre_v->next = p->next;
    p->next->pre_v = p->pre_v;
}

void link_traverse(void (*link_fun)(link))
{
    link p;
    for (p = head->next; p != head ; p = p->next) {
        link_fun(p);
    }

}


void link_destroy(void)
{
    link q, p = head->next;
    head->next = head;
    head->pre_v = head;
    while (p != head) {
        q = p;
        p = p->next;
        link_free_node(q);
    }
}

void link_FIFO_IN(link p)
{
    link_insert(p);
}

link link_FIFO_OUT(void)
{
    if (head->next == head) {
        return NULL;
    } else {
        link p = head->pre_v;
        link_delete(p);
        return p;
    }

}

