#include "array.h"

array_t *array_init(size_t initial_size) {
    array_t *arr = malloc(sizeof(array_t));
    if (!arr) return NULL;

    arr->buffer = malloc(sizeof(void *) * initial_size);
    if (!arr->buffer) {
        free(arr);
        return NULL;
    }

    arr->size = initial_size;
    arr->len = 0;
    return arr;
}

bool array_add(array_t *array, void *item) {
    if (array->len >= array->size) {
        size_t new_size = array->size * 2;
        void **new_buffer = realloc(array->buffer, sizeof(void *) * new_size);
        if (!new_buffer) return false;

        array->buffer = new_buffer;
        array->size = new_size;
    }

    array->buffer[array->len++] = item;
    return true;
}

void *array_at(array_t *array, size_t idx) {
    if (idx >= array->len) return NULL;
    return array->buffer[idx];
}

void *array_find(array_t *array, void *target_item, size_t item_size) {
    array_foreach(array, idx) {
        if (memcmp(target_item, array->buffer[idx], item_size) == 0) {
            return array->buffer[idx];
        }
    }
    return NULL;
}

bool array_write(array_t *array, size_t idx, void *data) {
    if (idx >= array->len) return false;
    array->buffer[idx] = data;
    return true;
}

void array_free(array_t *array) {
    if (array) {
        free(array->buffer);
        free(array);
    }
}
