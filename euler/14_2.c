/**
 * @author      : pupil (pupil@$HOSTNAME)
 * @file        : 14
 * @created     : Wednesday Aug 07, 2024 20:45:45 CST
 */

#include <stdio.h>
#define MAX 10000000

long long mem[MAX + 5] = {0};

int getLen(long long n) {
  if (n == 1)
    return 1;
  if (n <= MAX && mem[n])
    return mem[n];
  int ret = ((n & 1) ? getLen(3 * n + 1) : getLen(n / 2)) + 1;
  if (n <= MAX)
    mem[n] = ret;
  return ret;
}

int main() {
  int maxLen = 0;
  int res = 0;
  for (int i = 2; i < MAX; i++) {
    int len = getLen(i);
    if (len <= maxLen)
      continue;
    maxLen = len;
    res = i;
  }
  printf("%d: %d\n", res, maxLen);
  return 0;
}
