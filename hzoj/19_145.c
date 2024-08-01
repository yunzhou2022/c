/**
 * @author      : yz
 * @file        : 19_145
 * @created     : Tuesday Jul 30, 2024 17:08:52 UTC
 */

#include <stdio.h>
#include <string.h>
int main() {
  int n;
  scanf("%d", &n);

  int max = -1, cur;
  char temp[105], res[105];
  for (int i = 0; i < n; i++) {
    scanf("%s", temp);
    cur = strlen(temp);
    if (cur > max) {
      strcpy(res, temp);
      max = cur;
    }
  }

  printf("%s\n", res);
  return 0;
}
