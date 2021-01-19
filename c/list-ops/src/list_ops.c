#include "list_ops.h"

#include <stdlib.h>

list_t *new_list(size_t length, list_element_t elements[]) {
    list_t *ret = (list_t *)malloc(sizeof(list_t));
    ret->length = length;
    ret->elements = (list_element_t *)malloc(sizeof(list_element_t) * length);

    for (size_t i = 0; i < length; ++i) {
        ret->elements[i] = elements[i];
    }

    return ret;
}

list_t *append_list(list_t *list1, list_t *list2) {
    list_t *ret = (list_t *)malloc(sizeof(list_t));
    ret->length = list1->length + list2->length;
    ret->elements = (list_element_t *)malloc(sizeof(list_element_t) * ret->length);

    size_t j = 0;
    for (size_t i = 0; i < list1->length; ++i) {
        ret->elements[j++] = list1->elements[i];
    }

    for (size_t i = 0; i < list2->length; ++i) {
        ret->elements[j++] = list2->elements[i];
    }

    return ret;
}

list_t *filter_list(list_t *list, bool (*filter)(list_element_t)) {
    int count = 0;
    for (size_t i = 0; i < list->length; ++i) {
        if (filter(list->elements[i])) {
            ++count;
        }
    }

    list_t *ret = (list_t *)malloc(sizeof(list_t));
    ret->length = count;
    ret->elements = (list_element_t *)malloc(sizeof(list_element_t) * count);

    size_t j = 0;
    for (size_t i = 0; i < list->length; ++i) {
        if (filter(list->elements[i])) {
            ret->elements[j++] = list->elements[i];
        }
    }

    return ret;
}

size_t length_list(list_t *list) {
    return list->length;
}

list_t *map_list(list_t *list, list_element_t (*map)(list_element_t)) {
    list_t *ret = (list_t *)malloc(sizeof(list_t));
    ret->length = list->length;
    ret->elements = (list_element_t *)malloc(sizeof(list_element_t) * list->length);

    for (size_t i = 0; i < list->length; ++i) {
        ret->elements[i] = map(list->elements[i]);
    }

    return ret;
}

// folds (reduces) the given list from the left with a function
list_element_t foldl_list(list_t *list, list_element_t initial, list_element_t (*foldl)(list_element_t, list_element_t)) {
    list_element_t acc = initial;
    for (size_t i = 0; i < list->length; ++i) {
        acc = foldl(acc, list->elements[i]);
    }

    return acc;
}

static list_element_t foldr_internal(int limit, int count, list_t *list, list_element_t initial,
                                     list_element_t (*foldr)(list_element_t, list_element_t)) {
    if (count == limit) {
        return initial;
    }

    list_element_t acc = foldr_internal(limit, count + 1, list, initial, foldr);
    return foldr(list->elements[count], acc);
}

list_element_t foldr_list(list_t *list, list_element_t initial, list_element_t (*foldr)(list_element_t, list_element_t)) {
    return foldr_internal(list->length, 0, list, initial, foldr);
}

list_t *reverse_list(list_t *list) {
    list_t *ret = (list_t *)malloc(sizeof(list_t));
    ret->length = list->length;
    ret->elements = (list_element_t *)malloc(sizeof(list_element_t) * list->length);

    for (size_t i = 0; i < list->length; ++i) {
        ret->elements[i] = list->elements[list->length - i - 1];
    }

    return ret;
}

void delete_list(list_t *list) {
    if (list == NULL) {
        return;
    }

    free(list->elements);
    free(list);
}
