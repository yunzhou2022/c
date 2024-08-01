/**
 * @author      : yz
 * @file        : 21_147
 * @created     : Tuesday Jul 30, 2024 17:27:10 UTC
 */

#include <stdio.h>
#include <string.h>

char s[10005];
int main() {
  scanf("%s", s);
  int n = strlen(s);
  char *res = (s[n - 1] % 2 == 0 ? "YES" : "NO");

  printf("%s\n", res);

  return 0;
}
