/**
 * @author      : yz
 * @file        : 07_3
 * @created     : Tuesday Aug 06, 2024 14:42:31 UTC
 */

#include <stdio.h>
#define MAX_N 100
int prime[MAX_N + 5] = {0};
void init() {
  for (int i = 2; i <= MAX_N; i++) {
    if (!prime[i]) prime[++prime[0]] = i;
    for (int j = 1; j <= prime[0]; j++) {
      if (prime[j] * i > MAX_N) break;
      prime[i * prime[j]] = 1;
      if (i % prime[j] == 0) break;
    }
  }
  return ;
}

int main() {
  init();

  for (int i = 1; i <= prime[0]; i++) {
    printf("%d\n", prime[i]);
  }

  return 0;
}
