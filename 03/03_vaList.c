/**
 * @author      : yz
 * @file        : 03_vaList
 * @created     : Sunday Jul 21, 2024 12:33:44 UTC
 */

#include <inttypes.h>
#include <stdarg.h>
#include <stdio.h>

int get_max(int n, ...) {
  va_list args;
  va_start(args, n);
  int res = INT32_MIN;
  for (int i = 0; i < n; i++) {
    int a = va_arg(args, int);
    if (a > res) {
      res = a;
    }
  }
  va_end(args);
  return res;
}
int main() {
  printf("max 2 8,7 %d\n", get_max(2, 8, 7));
  printf("max 3 8,7,9 %d\n", get_max(3, 8, 7, 9));

  return 0;
}
