/**
 * @author      : yz
 * @file        : 07_test1
 * @created     : Tuesday Aug 06, 2024 14:04:49 UTC
 */

#include <stdio.h>
#define MAX 100

int notPrime[MAX + 5] = {0};

void init() {
  for (int i = 2; i <= MAX; i++) {
    if (notPrime[i]) continue;
    notPrime[i] = i;
    for (int j = i * 2; j <= MAX; j += i) {
      if (notPrime[j]) continue;
      notPrime[j] = i;
    }
  }
}

int main() {
  init();
  for (int i = 1; i <= MAX; i++) {
    printf("min(%d) = %d\n", i, notPrime[i]);
  }
  return 0;
}
