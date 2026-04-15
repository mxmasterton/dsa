#include <inttypes.h>
#include <stdlib.h>

#include "linked_list.h"

/*
struct linked_node_t {
    int value;
    struct linked_node_t* next;
};

typedef struct {
    struct linked_node_t* head;
    size_t size;
} linked_list_t;
*/

// lifecycle
linked_list_t* create_linked_list() {
    linked_list_t* list = malloc(sizeof(linked_list_t));
    if (!list) {
        return NULL;
    }

    list->head = malloc(sizeof(struct linked_node_t));
    if (!list->head) {
        free(list);
        return NULL;
    }
    list->head->next = NULL;

    list->size = 0;
    return list;
}

void free_linked_list(linked_list_t* list) {
    if (list) {
        struct linked_node_t* current = list->head;
        struct linked_node_t* next;

        while (current) {
            next = current->next;
            free(current);
            current = next;
        }

        free(list);
    }
}

// helper function
static struct linked_node_t* previous_node(linked_list_t* list, size_t index) {
    struct linked_node_t* current = list->head;
    for (size_t i = 0; i < index; i++) {
        current = current->next;
    }
    return current;
}

// core operations
int linked_list_insert(linked_list_t* list, size_t index, int value) {
    if (!list || index > list->size) {
        return 0;
    }

    struct linked_node_t* new_node = malloc(sizeof(struct linked_node_t));
    if (!new_node) {
        return 0;
    }
    new_node->value = value;

    struct linked_node_t* previous = previous_node(list, index);
    new_node->next = previous->next;
    previous->next = new_node;

    list->size++;
    return 1;
}

int linked_list_remove(linked_list_t* list, size_t index, int* out) {
    if (!list || index >= list->size) {
        return 0;
    }

    struct linked_node_t* previous = previous_node(list, index);
    struct linked_node_t* remove = previous->next;

    previous->next = remove->next;
    if (out) {
        *out = remove->value;
    }
    free(remove);
    list->size--;
    return 1;
}

int linked_list_get(const linked_list_t* list, size_t index, int* out) {
    if (!list || index >= list->size || !out) {
        return 0;
    }

    struct linked_node_t* current = list->head->next;
    for (size_t i = 0; i < index; i++) {
        current = current->next;
    }

    *out = current->value;
    return 1;
}

int linked_list_set(linked_list_t* list, size_t index, int value) {
    if (!list || index >= list->size) {
        return 0;
    }

    struct linked_node_t* current = list->head->next;
    for (size_t i = 0; i < index; i++) {
        current = current->next;
    }

    current->value = value;
    return 1;
}

// helper functions
int linked_list_size(const linked_list_t* list, size_t* out) {
    if (!list || !out) {
        return 0;
    }

    *out = list->size;
    return 1;
}
