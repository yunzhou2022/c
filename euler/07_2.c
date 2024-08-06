/**
 * @author      : yz
 * @file        : 07_2
 * @created     : Tuesday Aug 06, 2024 13:21:18 UTC
 */

#include <stdio.h>
#define MAX 200000

int notPrime[MAX + 5] = {0};

void init() {
  for (int i = 2; i <= MAX; i++) {
    if (notPrime[i]) continue;
    notPrime[++notPrime[0]] = i;
    for (int j = i * 2; j <= MAX; j += i) {
      notPrime[j] = 1;
    }
  }
}

int main() {
  init();
  printf("%d\n", notPrime[10001]);

  return 0;
}
