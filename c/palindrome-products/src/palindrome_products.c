#include "palindrome_products.h"

#include <limits.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

static int is_palindrome(int n) {
    int v[32] = {0};
    int i = 0;
    while (n > 0) {
        v[i++] = n % 10;
        n /= 10;
    }

    if (i == 1) {
        return 1;
    }

    for (int j = 0; j <= i / 2; ++j) {
        if (v[j] != v[i - j - 1]) {
            return 0;
        }
    }

    return 1;
}

static void free_factors(factor_t *p) {
    while (p != NULL) {
        factor_t *tmp = p->next;
        free(p);
        p = tmp;
    }
}

static void append_factors(factor_t **p, int a, int b) {
    if (*p == NULL) {
        factor_t *f = (factor_t *)malloc(sizeof(factor_t));
        f->factor_a = a;
        f->factor_b = b;
        f->next = NULL;
        *p = f;
        return;
    }

    factor_t *f = *p;
    while (f->next != NULL) {
        f = f->next;
    }

    factor_t *f2 = (factor_t *)malloc(sizeof(factor_t));
    f2->factor_a = a;
    f2->factor_b = b;
    f2->next = NULL;
    f->next = f2;
}

product_t *get_palindrome_product(int from, int to) {
    product_t *p = (product_t *)malloc(sizeof(product_t));
    p->factors_sm = NULL;
    p->factors_lg = NULL;
    if (from > to) {
        sprintf(p->error, "invalid input: min is %u and max is %u", from, to);
        return p;
    }

    int min = INT_MAX;
    int max = INT_MIN;
    for (int i = from; i <= to; ++i) {
        for (int j = from; j <= to; ++j) {
            int mul = i * j;
            if (is_palindrome(mul)) {
                if (mul < min) {
                    free_factors(p->factors_sm);
                    p->factors_sm = NULL;
                    append_factors(&(p->factors_sm), i, j);
                    min = mul;
                } else if (min == mul) {
                    append_factors(&(p->factors_lg), i, j);
                }

                if (mul > max) {
                    free_factors(p->factors_lg);
                    p->factors_lg = NULL;
                    append_factors(&(p->factors_lg), i, j);
                    max = mul;
                } else if (max == mul) {
                    append_factors(&(p->factors_lg), i, j);
                }
            }
        }
    }

    if (min == INT_MAX && max == INT_MIN) {
        sprintf(p->error, "no palindrome with factors in the range %u to %u", from, to);
    } else {
        p->smallest = min;
        p->largest = max;
    }

    return p;
}

void free_product(product_t *p) {
    if (p == NULL) {
        return;
    }

    free_factors(p->factors_sm);
    free_factors(p->factors_lg);
}
