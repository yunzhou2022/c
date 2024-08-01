/**
 * @author      : yz
 * @file        : 08_103
 * @created     : Saturday Jul 20, 2024 14:24:31 UTC
 */

#include <stdio.h>

int main() {
  int a, b;
  scanf("%d%d", &a, &b);
  printf("%s\n", a % b ? "NO" : "YES");

  return 0;
}
