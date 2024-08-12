#include <math.h>
#include <stdio.h>

int F(int n) {
  int I = sqrt(n);
  int cnt = 0;
  for (int i = 1; i <= I; i++) {
    if (n % i == 0)
      cnt += 2;
  }
  if (I * I == n)
    cnt--;
  return cnt;
}

int getLen(int n) {

  if (n & 1) {
    return F(n) * F((n + 1) >> 1);
  }
  return F(n / 2) * F(n + 1);
}

int main() {
  for (int i = 1;; i++) {
    int len = getLen(i);
    if (len <= 500)
      continue;
    printf("%lld\n", i * (i + 1LL) / 2);
    break;
  }
  return 0;
}
