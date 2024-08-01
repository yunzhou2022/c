/**
 * @author      : yz
 * @file        : 02_gcd
 * @created     : Sunday Jul 21, 2024 11:35:57 UTC
 */

#include <stdio.h>

int gcd(int a, int b) {
  if (b == 0) {
    return a;
  }

  return gcd(b, a % b);
}

int main() {
  int a, b;
  scanf("%d%d", &a, &b);
  int res = gcd(a, b);
  printf("%d\n", res);
  return 0;
}
