#include <stdlib.h>

#include "dynamic_array.h"

/*
typedef struct {
    int* data;
    size_t size;
    size_t capacity;
} dynamic_array_t;
*/

// lifecycle
dynamic_array_t* create_dynamic_array() {
    dynamic_array_t* array = malloc(sizeof(dynamic_array_t));
    if (!array) {
        return NULL;
    }

    array->data = malloc(10 * sizeof(int));
    if (!array->data) {
        free(array);
        return NULL;
    }

    array->size = 0;
    array->capacity = 10;
    return array;
}

void free_dynamic_array(dynamic_array_t* array) {
    if (array) {
        free(array->data);
        free(array);
    }
}

// core operators
static int dynamic_array_resize(dynamic_array_t* array) {
    if (!array || !array->data) {
        return 0;
    }

    int* new_data = realloc(array->data, 2 * array->capacity * sizeof(int));
    if (!new_data) {
        return 0;
    }

    array->data = new_data;
    array->capacity *= 2;
    return 1;
}

int dynamic_array_push(dynamic_array_t* array, int value) {
    if (!array || !array->data) {
        return 0;
    }

    // resize if needed
    if (array->size == array->capacity) {
        if (!dynamic_array_resize(array)) {
            return 0;
        }
    }

    array->data[array->size] = value;
    array->size++;
    return 1;
}

int dynamic_array_pop(dynamic_array_t* array, int* out) {
    if (!array || !array->data) {
        return 0;
    }

    if (array->size == 0) {
        return 0;
    }

    array->size--;
    if (out) {
        *out = array->data[array->size];
    }
    return 1;
}

int dynamic_array_get(const dynamic_array_t* array, size_t index, int* out) {
    if (!array || !array->data || !out) {
        return 0;
    }

    if (index >= array->size) {
        return 0;
    }

    *out = array->data[index];
    return 1;
}

int dynamic_array_set(dynamic_array_t* array, size_t index, int value) {
    if (!array || !array->data) {
        return 0;
    }

    if (index >= array->size) {
        return 0;
    }

    array->data[index] = value;
    return 1;
}

int dynamic_array_insert(dynamic_array_t* array, size_t index, int value) {
    if (!array || !array->data) {
        return 0;
    }

    if (index > array->size) {
        return 0;
    }

    // resize if needed
    if (array->size == array->capacity) {
        if (!dynamic_array_resize(array)) {
            return 0;
        }
    }

    // shift elements right
    for (size_t i = array->size; i > index; i--) {
        array->data[i] = array->data[i - 1];
    }

    array->data[index] = value;
    array->size++;
    return 1;
}

int dynamic_array_remove(dynamic_array_t* array, size_t index, int* out) {
    if (!array || !array->data) {
        return 0;
    }

    if (index >= array->size) {
        return 0;
    }

    if (out) {
        *out = array->data[index];
    }

    // shift elements left
    for (size_t i = index; i < array->size - 1; i++) {
        array->data[i] = array->data[i + 1];
    }

    array->size--;
    return 1;
}

// helper functions
int dynamic_array_size(const dynamic_array_t* array, size_t* out) {
    if (!array || !out) {
        return 0;
    }

    *out = array->size;
    return 1;
}
