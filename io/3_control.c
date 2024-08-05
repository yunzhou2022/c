/**
 * @author      : yz
 * @file        : 3_control
 * @created     : Thursday Aug 01, 2024 17:39:13 UTC
 */

#include <stdio.h>

int main() {
  char a[100];
  while ((scanf("%[^\n]", a) != EOF)) {
      getchar();
    printf("%s\n", a);
  }

  return 0;
}
