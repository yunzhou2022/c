#include <inttypes.h>
#include <stdio.h>

long long pentagonal(long long n) { return n * (3 * n - 1) / 2; }

int isValid(long long val) {
  long long s = 1, e = val, mid;
  while (s <= e) {
    mid = (s + e) >> 1;
    long long temp = pentagonal(mid);
    if (temp == val) {
      return 1;
    }
    if (temp < val)
      s = mid + 1;
    else
      e = mid - 1;
  }

  return 0;
}

int main() {
  long long j = 1, ans = INT32_MAX;
  while (pentagonal(j + 1) - pentagonal(j) < ans) {
    j++;
    for (int i = j - 1; i >= 1 && pentagonal(j) - pentagonal(i) < ans; i--) {
      long long a = pentagonal(j), b = pentagonal(i);
      if (!isValid(a - b))
        continue;
      if (!isValid(a + b))
        continue;
      printf("%lld %lld\n", a, b);
      ans = a - b;
    }
  }
  printf("%lld\n", ans);
  return 0;
}
