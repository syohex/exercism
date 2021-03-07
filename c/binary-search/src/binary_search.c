#include "binary_search.h"

int *binary_search(int value, const int *arr, size_t length) {
    int left = 0;
    int right = (int)length - 1;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == value) {
            return (int *)&arr[mid];
        }

        if (arr[mid] > value) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return NULL;
}
