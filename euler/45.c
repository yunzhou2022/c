#include <stdio.h>

#define ll long long

ll P(ll n) { return n * (3 * n - 1) / 2; }

ll H(ll n) { return n * (2 * n - 1); }

int bs(ll (*fn)(ll), ll n) {
  ll s = 1, e = n, mid;
  while (s <= e) {
    mid = (s + e) >> 1;
    if (fn(mid) == n)
      return 1;
    if (fn(mid) < n)
      s = mid + 1;
    else
      e = mid - 1;
  }

  return 0;
}

int main() {
  ll n = 144;
  while (!bs(P, H(n)))
    n++;

  printf("%lld\n", H(n));
  return 0;
}
