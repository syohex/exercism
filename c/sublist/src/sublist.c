#include "sublist.h"

#include <string.h>
#include <stdio.h>

comparison_result_t check_lists(int *list_to_compare, int *base_list, size_t list_to_compare_element_count,
                                size_t base_list_element_count) {
    if (list_to_compare_element_count == base_list_element_count) {
        if (memcmp(list_to_compare, base_list, sizeof(int) * list_to_compare_element_count) == 0) {
            return EQUAL;
        }

        return UNEQUAL;
    }

    if (list_to_compare_element_count > base_list_element_count) {
        int len = list_to_compare_element_count - base_list_element_count;
        for (int i = 0; i <= len; ++i) {
            if (memcmp(list_to_compare + i, base_list, sizeof(int) * base_list_element_count) == 0) {
                return SUPERLIST;
            }
        }

        return UNEQUAL;
    }

    int len = base_list_element_count - list_to_compare_element_count;
    for (int i = 0; i <= len; ++i) {
        if (memcmp(base_list + i, list_to_compare, sizeof(int) * list_to_compare_element_count) == 0) {
            return SUBLIST;
        }
    }

    return UNEQUAL;
}
