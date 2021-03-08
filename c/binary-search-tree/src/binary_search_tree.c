#include "binary_search_tree.h"

#include <stdlib.h>

node_t *build_tree(int *tree_data, size_t tree_data_len) {
    if (tree_data_len == 0) {
        return NULL;
    }

    node_t *root = (node_t *)malloc(sizeof(node_t));
    root->data = tree_data[0];
    root->left = root->right = NULL;

    for (size_t i = 1; i < tree_data_len; ++i) {
        node_t *p = root;
        while (1) {
            if (tree_data[i] <= p->data) {
                if (p->left == NULL) {
                    node_t *q = (node_t *)malloc(sizeof(node_t));
                    q->data = tree_data[i];
                    q->left = q->right = NULL;
                    p->left = q;
                    break;
                }

                p = p->left;
            } else {
                if (p->right == NULL) {
                    node_t *q = (node_t *)malloc(sizeof(node_t));
                    q->data = tree_data[i];
                    q->left = q->right = NULL;
                    p->right = q;
                    break;
                }

                p = p->right;
            }
        }
    }

    return root;
}

void free_tree(node_t *tree) {
    if (tree == NULL) {
        return;
    }

    free_tree(tree->left);
    free_tree(tree->right);

    free(tree);
}

static void collect_sorted_data(node_t *node, int *ret, size_t *count) {
    if (node == NULL) {
        return;
    }

    collect_sorted_data(node->left, ret, count);
    ret[*count] = node->data;
    ++(*count);
    collect_sorted_data(node->right, ret, count);
}

int *sorted_data(node_t *tree) {
    int *ret = (int *)malloc(sizeof(int) * 1024);
    size_t pos = 0;
    collect_sorted_data(tree, ret, &pos);
    return ret;
}
