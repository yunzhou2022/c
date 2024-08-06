/**
 * @author      : yz
 * @file        : 03
 * @created     : Tuesday Aug 06, 2024 04:32:17 UTC
 */

#include <stdio.h>
#define ll long long

int isPrime(ll x) {
  for (ll i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      return 0;
    }
  }
  return 1;
}

int main() {
  ll target = 600851475143;
  int res = 0;
  for (ll i = 2; i * i <= target; i++) {
    if (target % i != 0) continue;
    if (!isPrime(i)) continue;
    res = i;
  }

  printf("%d\n", res);

  return 0;
}
