/**
 * @author      : yz
 * @file        : 03_2
 * @created     : Tuesday Aug 06, 2024 04:46:39 UTC
 */

#include <stdio.h>
#define MAX_N 600851475143LL
#define ll long long

int main() {
  ll ans = 0, i = 2, N = MAX_N;
  while (i * i <= N) {
//    if (N % i == 0) ans = i;
    while (N % i == 0) N /= i;
    i += 1;
  }
  if (N != 1) ans = N;
  printf("%lld\n", ans);

  return 0;
}
