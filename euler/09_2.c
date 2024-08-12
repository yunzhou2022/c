#include <stdio.h>

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

int main() {
  for (int n = 1; n < 33; n++) {
    for (int m = n + 1; m < 33; m++) {
      // if (((n ^ m) & 1) == 0)
      //   continue;
      if (gcd(n, m) != 1)
        continue;

      int a = 2 * n * m;
      int b = m * m - n * n;
      int c = m * m + n * n;
      if (1000 % (a + b + c) != 0)
        continue;
      int k = 1000 / (a + b + c);
      printf("%d %d\n", n, m);
      printf("%d %d %d\n", a, b, c);
      printf("%d\n", a * b * c * k * k * k);
      return 0;
    }
  }
  return 0;
}
