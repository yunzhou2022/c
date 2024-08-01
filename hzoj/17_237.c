/**
 * @author      : yz
 * @file        : 17_237
 * @created     : Monday Jul 22, 2024 15:31:04 UTC
 */

#include <stdio.h>

int arr[10], vis[10] = {0};
void print(int n) {
  for (int i = 0; i < n; i++) {
    if (i)
      printf(" ");
    printf("%d", arr[i]);
  }
  printf("\n");
  return;
}
void f(int i, int n) {
  if (i == n) {
    print(n);
    return;
  }
  for (int k = 1; k <= n; k++) {
    if (vis[k]) {
      continue;
    }
    vis[k] = 1;
    arr[i] = k;
    f(i + 1, n);
    vis[k] = 0;
  }
  return;
}
int main() {
  int n;
  scanf("%d", &n);
  f(0, n);
  return 0;
}
