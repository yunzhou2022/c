#include <stdio.h>

int bs(int *arr, int target, int *times, int start, int end) {
  *times += 1;
  if (start > end)
    return -1;
  int mid = (start + end) >> 1;
  if (arr[mid] == target)
    return mid;
  if (arr[mid] < target)
    return bs(arr, target, times, mid + 1, end);
  return bs(arr, target, times, start, mid - 1);
}

// int bs(int *arr, int target, int *times) {
//   int s = 0, end = 9;
//   while (s <= end) {
//     int mid = (s + end) >> 1;
//     (*times)++;
//     if (arr[mid] == target)
//       return mid;
//     if (arr[mid] < target)
//       s = mid + 1;
//     if (arr[mid] > target)
//       end = mid - 1;
//   }
//
//   return -1;
// }
//
int main() {
  int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  int target = 3;
  while (scanf("%d", &target) != EOF) {
    int times = 0;
    int index = bs(arr, target, &times, 0, 9);
    printf("%d is in %d, find %d times\n", target, index, times);
  }
  return 0;
}
