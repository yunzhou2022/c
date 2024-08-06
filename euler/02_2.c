/**
 * @author      : yz
 * @file        : 02
 * @created     : Monday Aug 05, 2024 16:43:54 UTC
 */

#include <stdio.h>

#define MAX 4000000
int main() {
  int sum = 2;
  int arr[3] = {0, 1, 2};
  int n = 3;
  while (arr[(n - 1) % 3] + arr[(n - 2) % 3] < MAX) {
    arr[n % 3] = arr[(n - 1) % 3] + arr[(n - 2) % 3];
    if (!(arr[n % 3] & 1)) sum += arr[n % 3];
    n++;
  }
  printf("%d\n", sum);
  return 0;
}
