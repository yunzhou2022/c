#include <stdio.h>

int main() {
  int a[400 + 5] = {1, 1};
  for (int i = 1; i <= 100; i++) {
    for (int j = 1; j <= a[0]; j++)
      a[j] *= 1024;
    for (int k = 1; k <= a[0]; k++) {
      if (a[k] < 10)
        continue;
      a[k + 1] += a[k] / 10;
      a[k] %= 10;
      a[0] += (a[0] == k);
    }
  }

  int res = 0;
  for (int i = 1; i <= a[0]; i++) {
    res += a[i];
  }

  printf("%d\n", res);

  return 0;
}
