/**
 * @author      : yz
 * @file        : 15_235
 * @created     : Monday Jul 22, 2024 13:48:51 UTC
 */

#include <stdio.h>

int arr[10];
void print_one_res(int n) {
  for (int i = 0; i <= n; i++) {
    if (i)
      printf(" ");
    printf("%d", arr[i]);
  }
  printf("\n");
  return;
}

void f(int i, int j, int n) {
  if (j > n)
    return;
  for (int k = j; k <= n; k++) {
    arr[i] = k;
    print_one_res(i);
    f(i + 1, k + 1, n);
  }
  return;
}
int main() {
  int n;
  scanf("%d", &n);
  f(0, 1, n);
  return 0;
}
