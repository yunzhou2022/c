/**
 * @author      : yz
 * @file        : 37
 * @created     : Tuesday Aug 06, 2024 15:25:29 UTC
 */

#include <math.h>
#include <stdio.h>
#define MAX_N 2000000
// #define MAX_N 100
int is_prime[MAX_N + 5] = {1, 1, 0};
int prime[MAX_N + 5] = {0};

void init() {
  for (int i = 2; i <= MAX_N; i++) {
    if (!is_prime[i]) prime[++prime[0]] = i;
    for (int j = 1; j <= prime[0]; j++) {
      if (prime[j] * i > MAX_N) break;
      is_prime[prime[j] * i] = 1;
      if (i % prime[j] == 0) break;
    }
  }
  return;
}

int isValid(int n) {
  int h = pow(10, floor(log10(n))), x = n;
  while (n) {
    if (is_prime[n]) return 0;
    n %= h;
    h /= 10;
  }

  while (x) {
    if (is_prime[x]) return 0;
    x /= 10;
  }

  return 1;
}
int main() {
  init();

  int len = 0;
  int sum = 0;
  for (int i = 5; i <= prime[0]; i++) {
    if (isValid(prime[i])) {
      len++;
      sum += prime[i];
      if (len == 11) {
        break;
      }
    }
    //     printf("%d\n", prime[i]);
  }

  printf("%d\n", sum);
  return 0;
}
