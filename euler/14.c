/**
 * @author      : pupil (pupil@$HOSTNAME)
 * @file        : 14
 * @created     : Wednesday Aug 07, 2024 20:45:45 CST
 */

#include <stdio.h>
#define MAX 10000000

int getLen(long long n) {
  long long len = 1;
  while (n != 1) {
    if (n & 1) {
      n = n * 3 + 1;
    } else {
      n = n / 2;
    }
    len++;
  }
  return len;
}

int main() {
  int maxLen = 0;
  int res = 0;
  for (int i = 2; i < MAX; i++) {
    int len = getLen(i);
    if (len > maxLen) {
      maxLen = len;
      res = i;
    }
  }
  printf("%d: %d\n", res, maxLen);
  return 0;
}
