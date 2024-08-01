/**
 * @author      : yz
 * @file        : 16_236
 * @created     : Monday Jul 22, 2024 14:03:45 UTC
 */

#include <stdio.h>

int arr[10];
void print_one_line(int n) {
  for (int i = 0; i < n; i++) {
    if (i)
      printf(" ");
    printf("%d", arr[i]);
  }
  printf("\n");
  return;
}
void f(int i, int j, int m, int n) {
  if (j > n)
    return;
  for (int k = j; k <= n; k++) {
    arr[i] = k;
    if (i == m - 1)
      print_one_line(m);
    f(i + 1, k + 1, m, n);
  }
  return;
}
int main() {
  int m, n;
  scanf("%d%d", &n, &m);
  f(0, 1, m, n);

  return 0;
}
