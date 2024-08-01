/**
 * @author      : yz
 * @file        : 07_102
 * @created     : Saturday Jul 20, 2024 10:34:37 UTC
 */

#include <stdio.h>

int main() {
  int a, b, c, t;
  scanf("%d%d%d%d", &a, &b, &c, &t);

  double res =
      (1.0 - (double)t / a - (double)t / b) / (1.0 / a + 1.0 / b - 1.0 / c);
  printf("%.2lf\n", res + t);
  return 0;
}
