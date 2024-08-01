/**
 * @author      : yz
 * @file        : 06_101
 * @created     : Saturday Jul 20, 2024 10:29:36 UTC
 */

#include <stdio.h>

int main() {
  char s[10];
  scanf("%s", s);
  int a = 0, b = 0, c = 0, d = 0;
  sscanf(s, "%1d%1d%1d%1d", &a, &b, &c, &d);
  printf("%d\n", a + b + c + d);

  return 0;
}
