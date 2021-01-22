#include "linked_list.h"

#include <stdlib.h>
#include <stdio.h>

struct list_node {
    struct list_node *prev, *next;
    ll_data_t data;
};
struct list {
    struct list_node *first, *last;
};

struct list *list_create(void) {
    struct list *lst = (struct list *)malloc(sizeof(struct list));
    lst->first = NULL;
    lst->last = NULL;
    return lst;
}

bool list_is_empty(const struct list *list) {
    return list->first == NULL;
}

bool list_push(struct list *list, ll_data_t item_data) {
    if (list == NULL) {
        return false;
    }

    struct list_node *node = (struct list_node *)malloc(sizeof(struct list_node));
    node->data = item_data;
    node->prev = NULL;
    node->next = NULL;

    if (list->first == NULL) {
        list->first = node;
        list->last = node;
    } else {
        list->last->next = node;
        node->prev = list->last;
        list->last = node;
    }

    return true;
}

ll_data_t list_pop(struct list *list) {
    int ret = list->last->data;
    struct list_node *new_last = list->last->prev;
    if (new_last != NULL) {
        new_last->next = NULL;
    } else {
        list->first = NULL;
    }

    free(list->last);

    list->last = new_last;
    return ret;
}

bool list_unshift(struct list *list, ll_data_t item_data) {
    if (list == NULL) {
        return false;
    }

    struct list_node *node = (struct list_node *)malloc(sizeof(struct list_node));
    node->data = item_data;
    node->prev = NULL;
    node->next = NULL;

    if (list->first == NULL) {
        list->first = node;
        list->last = node;
    } else {
        node->next = list->first;
        list->first->prev = node;
        list->first = node;
    }

    return true;
}

ll_data_t list_shift(struct list *list) {
    int ret = list->first->data;
    struct list_node *new_first = list->first->next;
    free(list->first);

    list->first = new_first;
    if (list->first == NULL) {
        list->last = NULL;
    }
    return ret;
}

void list_destroy(struct list *list) {
    if (list == NULL) {
        return;
    }

    struct list_node *p = list->first;
    while (p != NULL) {
        struct list_node *tmp = p->next;
        free(p);
        p = tmp;
    }

    free(list);
}
