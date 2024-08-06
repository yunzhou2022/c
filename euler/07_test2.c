/**
 * @author      : yz
 * @file        : 07_test2
 * @created     : Tuesday Aug 06, 2024 14:12:59 UTC
 */

#include <stdio.h>
#define MAX 100
int prime[MAX + 5] = {0};

void init() {
  for (int i = 2; i <= MAX; i++) {
    if (prime[i]) continue;
    prime[i] = i;
    for (int j = 2 * i; j <= MAX; j += i) {
      prime[j] = i;
    }
  }
}

int main() {
  init();
  for (int i = 0; i <= MAX; i++) {
    printf("max(%d) = %d\n", i, prime[i]);
  }
  return 0;
}
