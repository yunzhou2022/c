#include <math.h>
#include <stdio.h>

long long triangle(int i) { return i * (i + 1) / 2; }

int getLen(long long val) {
  int cnt = 0;
  long long I = sqrt(val);
  for (int i = 1; i <= I; i++) {
    if (val % i == 0)
      cnt += 2;
  }
  if (I * I == val)
    cnt--;

  return cnt;
}

int main() {
  for (int i = 1;; i++) {
    long long num = triangle(i);
    int len = getLen(num);
    if (len <= 500)
      continue;
    printf("%lld\n", num);
    break;
  }

  return 0;
}
