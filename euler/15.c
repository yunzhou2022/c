#include <stdio.h>

int main() {
  long long res = 1;
  for (int i = 21, j = 1; i <= 40; i++) {
    res = res * i;
    while (res > j && j <= 20 && res % j == 0) {
      res /= j;
      j++;
    }
  }
  printf("%lld\n", res);
  return 0;
}
