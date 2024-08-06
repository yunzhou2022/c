/**
 * @author      : yz
 * @file        : 05
 * @created     : Tuesday Aug 06, 2024 05:02:15 UTC
 */

#include <stdio.h>

#define ll long long

int gcd(ll  a, ll  b) {
  if (!b) return a;
  return gcd(b, a % b);
}

int beishu(ll  a, ll  b) { return a * b / gcd(a, b); }

int main() {
  int x = 1;
  for (ll  i = 2; i <= 20; i++) {
    x = beishu(x, i);
  }
  printf("%d\n", x);

  return 0;
}
