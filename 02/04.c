/**
 * @author      : yz
 * @file        : 04
 * @created     : Saturday Jul 20, 2024 09:14:46 UTC
 */

#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);
  int t = 1;
  while (t <= n) {
    int t2 = t & n;
    if ((t ^ t2) == 0) {
      printf("%d\n", t);
      return 0;
    }
    t = t << 1;
  }
  printf("not found!\n");
  return 0;
}
