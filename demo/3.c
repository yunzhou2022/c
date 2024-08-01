#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quick_sort(int *arr, int l, int r) {
    if (l >= r) {
        return;
    }

    int start = l, end = r;
    int pivot = arr[start];

    while (l < r) {
        while (l < r && arr[r] >= pivot) {
            r--;
        }
        if (l < r) {
            arr[l] = arr[r];
            l++;
        }
        while (l < r && arr[l] <= pivot) {
            l++;
        }
        if (l < r) {
            arr[r] = arr[l];
            r--;
        }
    }

    arr[l] = pivot;
    quick_sort(arr, start, l - 1);
    quick_sort(arr, l + 1, end);
}

int main() {
    int arr[10] = {3, 5, 2, 1, 4, 7, 6, 9, 8, 10};

    printf("Before sorting: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    quick_sort(arr, 0, 9);

    printf("After sorting: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

