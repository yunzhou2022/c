/**
 * @author      : yz
 * @file        : 02
 * @created     : Monday Aug 05, 2024 16:43:54 UTC
 */

#include <stdio.h>

void fib(int a, int b, int *sum) {
  if (b < 4000000) {
    if (b % 2 == 0) {
      (*sum) += b;
    }
    fib(b, a + b, sum);
  }
}

int main() {
  int sum = 0;
  fib(1, 2, &sum);
  printf("%d\n", sum);
  return 0;
}
