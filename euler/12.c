#include <stdio.h>

#define ll long long

ll getLen(ll n) {
  int len = 0;
  for (ll i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      len += 2;
    }
  }
  return len;
}

ll sanJiao(ll i) { return (1 + i) * i / 2; }

int main() {
  ll i = 1;
  while (getLen(sanJiao(i)) <= 500)
    i++;
  printf("%lld, %lld,  %lld\n", i, getLen(sanJiao(i)), sanJiao(i));
  return 0;
}
