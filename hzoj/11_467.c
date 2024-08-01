/**
 * @author      : yz
 * @file        : 11_467
 * @created     : Monday Jul 22, 2024 04:52:58 UTC
 */

#include <stdio.h>

long long factorial(int n) {
  if (n == 1) {
    return 1;
  }
  return n * factorial(n - 1);
}

int main() {
  int n;
  scanf("%d", &n);
  printf("%lld\n", factorial(n));

  return 0;
}
