#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <stddef.h>

typedef struct {
    int* data;
    size_t size;
    size_t capacity;
} dynamic_array_t;

// lifecycle
dynamic_array_t* create_dynamic_array();
void free_dynamic_array(dynamic_array_t* array);

// core operations
int dynamic_array_push(dynamic_array_t* array, int value);
int dynamic_array_pop(dynamic_array_t* array, int* out);

int dynamic_array_get(const dynamic_array_t* array, size_t index, int* out);
int dynamic_array_set(dynamic_array_t* array, size_t index, int value);

int dynamic_array_insert(dynamic_array_t* array, size_t index, int value);
int dynamic_array_remove(dynamic_array_t* array, size_t index, int* out);

// helper functions
int dynamic_array_size(const dynamic_array_t* array, size_t* out);

#endif
