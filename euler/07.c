/**
 * @author      : yz
 * @file        : 07
 * @created     : Tuesday Aug 06, 2024 13:05:14 UTC
 */

#include <math.h>
#include <stdio.h>
#define MAX 200000

int isPrime(int n) {
  for (int i = 2, I = sqrt(n); i <= I; i++) {
    if (n % i == 0) return 0;
  }
  return 1;
}

int main() {
  int len = 0;
  int res;

  for (int i = 2; i < MAX; i++) {
    if (!isPrime(i)) continue;
    len++;
    if (len == 10001) {
      res = i;
      break;
    }
  }

  printf("%d\n", res);
  return 0;
}
