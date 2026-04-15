#ifndef STACK_H
#define STACK_H

#include "dynamic_array.h"

typedef struct {
    dynamic_array_t* data;
} stack_t;

// lifecycle
stack_t* create_stack();
void free_stack(stack_t* stack);

// core operations
int stack_push(stack_t* stack, int value);
int stack_pop(stack_t* stack, int* out);
int stack_peek(const stack_t* stack, int* out);

// helper functions
int stack_size(const stack_t* stack, size_t* out);

#endif
