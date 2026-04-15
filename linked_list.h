#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stddef.h>

struct linked_node_t {
    int value;
    struct linked_node_t* next;
};

typedef struct {
    struct linked_node_t* head;
    size_t size;
} linked_list_t;

// lifecycle
linked_list_t* create_linked_list();
void free_linked_list(linked_list_t* list);

// core operations
int linked_list_insert(linked_list_t* list, size_t index, int value);
int linked_list_remove(linked_list_t* list, size_t index, int* out);

int linked_list_get(const linked_list_t* list, size_t index, int* out);
int linked_list_set(linked_list_t* list, size_t index, int value);

// helper functions
int linked_list_size(const linked_list_t* list, size_t* out);

#endif
