/**
 * @author      : yz
 * @file        : 35
 * @created     : Tuesday Aug 06, 2024 15:01:39 UTC
 */

#include <math.h>
#include <stdio.h>
#define MAX_N 1000000

int isPrime[MAX_N] = {0, 1};
int prime[MAX_N] = {0};

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

int isValid(int x) {
  int n = floor(log10(x)) + 1;
  int len = n - 1;
  while (len) {
    x = x % 10 * (int)pow(10, n - 1) + x / 10;
    if (isPrime[x]) return 0;
    len--;
  }

  return 1;
}

int main() {
  init();
  int len = 0;
  for (int i = 1; i <= prime[0]; i++) {
    if (!isValid(prime[i])) continue;
    printf("x = %d\n", prime[i]);
    len++;
  }

  printf("%d\n", len);

  return 0;
}
