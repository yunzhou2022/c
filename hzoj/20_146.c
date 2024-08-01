/**
 * @author      : yz
 * @file        : 20_146
 * @created     : Tuesday Jul 30, 2024 17:12:59 UTC
 */

#include <ctype.h>
#include <stdio.h>

int main() {
  char s[55];
  scanf("%s", s);
  for (int i = 0; s[i]; i++) {
    if (s[i] == 'z') {
      s[i] = 'a';
      continue;
    }
    if (s[i] == 'Z') {
      s[i] = 'A';
      continue;
    }
    if (isalpha(s[i])) {
      s[i]++;
    }
  }
  printf("%s\n", s);
  return 0;
}
