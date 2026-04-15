#include <stdlib.h>

#include "stack.h"
#include "dynamic_array.h"

/*
typedef struct {
    dynamic_array_t* data;
} stack_t;
*/

// lifecycle
stack_t* create_stack() {
    stack_t* stack = malloc(sizeof(stack_t));
    if (!stack) {
        return NULL;
    }

    stack->data = create_dynamic_array();
    if (!stack->data) {
        free(stack);
        return NULL;
    }

    return stack;
}

void free_stack(stack_t* stack) {
    if (stack) {
        free_dynamic_array(stack->data);
        free(stack);
    }
}

// core operations
int stack_push(stack_t* stack, int value) {
    if (!stack) {
        return 0;
    }

    return dynamic_array_push(stack->data, value);
}

int stack_pop(stack_t* stack, int* out) {
    if (!stack) {
        return 0;
    }

    return dynamic_array_pop(stack->data, out);
}

int stack_peek(const stack_t* stack, int* out) {
    if (!stack || !stack->data) {
        return 0;
    }

    size_t size;
    dynamic_array_size(stack->data, &size);
    if (size == 0) {
        return 0;
    }

    return dynamic_array_get(stack->data, size - 1, out);
}

// helper functions
int stack_size(const stack_t* stack, size_t* out) {
    if (!stack) {
        return 0;
    }

    return dynamic_array_size(stack->data, out);
}
