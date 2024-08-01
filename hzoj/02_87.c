/**
 * @author      : yz
 * @file        : 02_87
 * @created     : Saturday Jul 20, 2024 10:07:55 UTC
 */

#include <stdio.h>

int main() {
  double a, b;
  scanf("%lf%lf", &a, &b);

  printf("%.2lf\n", 2.0 * (a + b));
  printf("%.2lf\n", a * b);

  return 0;
}
