#include <stdio.h>
#include <math.h>
int jumpSearch(int arr[], int size, int tar) {
    int step = sqrt(size);
    int prev = 0;
    while (arr[fmin(step, size) - 1] < tar) {
        prev = step;
        step += sqrt(size);
        if (prev >= size) {
            return -1;
        }
    }
    for (int i = prev; i < fmin(step, size); i++) {
        if (arr[i] == tar) {
            return i;
        }
    }
    return -1;
}
int main() {
    int arr[20], i, n, tar, res;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements of the array in sorted order:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the target value to search: ");
    scanf("%d", &tar);
    res = jumpSearch(arr, n, tar);
    if (res != -1) {
        printf("Element found at index %d\n", res);
    } else {
        printf("Element not found in the array\n");
    }
    return 0;
}