/**
 * @author      : yz
 * @file        : 01_2
 * @created     : Monday Aug 05, 2024 16:15:28 UTC
 */

#include <stdio.h>

int sum(int start, int end) {
  return (start + (end - 1) / start * start) * ((end - 1) / start) / 2;
}

int main() {
  int sum3 = sum(3, 1000);
  int sum5 = sum(5, 1000);
  int sum15 = sum(15, 1000);
  printf("%d\n", sum3 + sum5 - sum15);
  return 0;
}
