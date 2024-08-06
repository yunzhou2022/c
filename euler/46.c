/**
 * @author      : yz
 * @file        : 46
 * @created     : Tuesday Aug 06, 2024 15:59:55 UTC
 */

#include <stdio.h>

#define MAX_N 2000000

int prime[MAX_N + 5] = {0};
int isPrime[MAX_N + 5] = {0};
int jihe[MAX_N + 5] = {0};

void init() {
  for (int i = 2; i <= MAX_N; i++) {
    if (!isPrime[i]) prime[++prime[0]] = i;
    for (int j = 1; j <= prime[0]; j++) {
      if (prime[j] * i > MAX_N) break;
      isPrime[prime[j] * i] = 1;
      if (i % prime[j] == 0) break;
    }
  }
}

void initjihe() {
  for (int i = 1; i <= prime[0]; i++) {
    for (int j = 1; j * j * 2 + prime[i] <= MAX_N; j++) {
      jihe[prime[i] + 2 * j * j] = 1;
    }
  }
}

int main() {
  init();
  initjihe();
  for (int i = 9; i <= MAX_N; i+=2) {
    if (isPrime[i] == 0) continue;
    if (jihe[i]) continue;
    printf("%d\n", i);
    break;
  }
  return 0;
}
