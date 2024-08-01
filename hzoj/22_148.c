/**
 * @author      : yz
 * @file        : 22_148
 * @created     : Tuesday Jul 30, 2024 17:30:36 UTC
 */

#include <stdio.h>
#include <string.h>

int main() {
  char s[55];
  scanf("%s", s);

  for (int i = 0, j = strlen(s) - 1; i < j; i++, j--) {
    s[i] ^= s[j];
    s[j] ^= s[i];
    s[i] ^= s[j];
  }
  printf("%s\n", s);

  return 0;
}
