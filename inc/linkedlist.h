#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct node* link;
struct node {
    unsigned char item;
    link next, pre_v;
};

link link_make_node(unsigned char item);
void link_free_node(link p);
link link_search(unsigned char key);
void link_insert(link p);
void link_insert_OD(link p);
void link_delete(link p);
void link_traverse(void (*link_fun)(link));
void link_destroy(void);
void link_FIFO_IN(link p);
link link_FIFO_OUT(void);

#endif
