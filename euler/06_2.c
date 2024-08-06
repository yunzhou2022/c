#include <stdio.h>

int main() {
  int n = 100;
  int sum1 = n * (n + 1) >> 1;
  int sum2 = n * (n + 1) * (2 * n + 1) / 6;

  int res =  sum1*sum1-sum2;
  printf("%d\n", res);

  return 0;
}
