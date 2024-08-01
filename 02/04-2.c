/**
 * @author      : yz
 * @file        : 04-2
 * @created     : Saturday Jul 20, 2024 09:26:16 UTC
 */

#include <stdio.h>

int main() {

  int n;
  while ((scanf("%d", &n)) != EOF) {
    printf("%d\n", n & -n);
  }

  return 0;
}
