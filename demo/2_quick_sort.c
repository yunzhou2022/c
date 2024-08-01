/**
 * @author      : yz
 * @file        : 2_quick_sort
 * @created     : Wednesday Jul 31, 2024 18:08:40 UTC
 */

#include <stdio.h>

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
  return;
}

void quick_sort(int *arr, int l, int r) {
  if (l >= r)
    return;

  int start = l, end = r;
  int z = arr[l];

  while (l < r) {
    while (r > l && arr[r] >= z)
      r--;
    if (r > l)
      arr[l++] = arr[r];
    while (l < r && arr[l] <= z)
      l++;
    if (l < r)
      arr[r--] = arr[l];
  }

  arr[l] = z;
  quick_sort(arr, start, l - 1);
  quick_sort(arr, l + 1, end);
  return;
}

int main() {
  int arr[10] = {3, 5, 2, 1, 4, 7, 6, 9, 8, 10};

  for (int i = 0; i < 10; i++) {
    printf("%d ", arr[i]);
  }

  printf("\n");

  quick_sort(arr, 0, 9);
  for (int i = 0; i < 10; i++) {
    printf("%d ", arr[i]);
  }

  return 0;
}
