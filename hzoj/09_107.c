/**
 * @author      : yz
 * @file        : 09_107
 * @created     : Saturday Jul 20, 2024 14:28:20 UTC
 */

#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);
  printf("%s\n", (n % 7 == 0 && n % 2 != 0) ? "YES" : "NO");

  return 0;
}
