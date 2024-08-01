/**
 * @author      : yz
 * @file        : 10_108
 * @created     : Sunday Jul 21, 2024 04:49:12 UTC
 */

#include <stdio.h>

int main() {
  char a[10];
  double w, h;
  scanf("%s", a);
  scanf("%lf%lf", &w, &h);
  printf("%.2lf\n", a[0] == 'r' ? w * h : w * h / 2.0);

  return 0;
}
