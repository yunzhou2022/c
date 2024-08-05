/**
 * @author      : yz
 * @file        : 01
 * @created     : Monday Aug 05, 2024 14:53:41 UTC
 */

#include <stdio.h>

int main() {
  int n = 1000;
  int sum = 0;
  for (int i = 0; i < n; i++) {
    if (i % 3 == 0 || i % 5 == 0) {
      sum += i;
    }
  }
  printf("%d", sum);
  return 0;
}
