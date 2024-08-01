/**
 * @author      : yz
 * @file        : 13_185
 * @created     : Monday Jul 22, 2024 04:59:50 UTC
 */

#include <stdio.h>

long long fib(int n) {
  if (n < 3)
    return 1;
  return fib(n - 1) + fib(n - 2);
}

int main() {
  int n;
  scanf("%d", &n);
  printf("%lld\n", fib(n));

  return 0;
}
