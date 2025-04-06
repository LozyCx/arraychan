#ifndef ARRAY_H
#define ARRAY_H

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    void **buffer;
    size_t size;
    size_t len;
} array_t;

#define array_foreach(_array, _idx) \
    for (size_t _idx = 0; _idx < (_array)->len; ++_idx)

array_t *array_init(size_t initial_size);

bool array_add(array_t *array, void *item);

void *array_at(array_t *array, size_t idx);
#define ARRAY_AT(array, idx, _type) ((_type) array_at(array, idx))

void *array_find(array_t *array, void *target_item, size_t item_sze);
#define ARRAY_FIND(array, target_item, _type) \
    ((_type*)array_find(array, (void*)target_item, sizeof(_type)))

    bool array_write(array_t *array, size_t idx, void *data);

void array_free(array_t *array);

#endif // ARRAY_H
