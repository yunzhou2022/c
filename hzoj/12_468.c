/**
 * @author      : yz
 * @file        : 12_468
 * @created     : Monday Jul 22, 2024 04:57:37 UTC
 */

#include <stdio.h>

int gcd(int m, int n) {
  if (n == 0)
    return m;
  return gcd(n, m % n);
}
int main() {
  int m, n;
  scanf("%d%d", &m, &n);
  printf("%d\n", gcd(m, n));

  return 0;
}
