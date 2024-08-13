#include <stdio.h>

int main() {
  int a[500] = {1, 1};
  long long res = 0;
  for (int i = 1; i <= 1000; i++) {
    for (int i = 1; i <= a[0]; i++) {
      a[i] *= 2;
    }
    for (int j = 1; j <= a[0]; j++) {
      if (a[j] < 10)
        continue;
      a[j + 1] += a[j] / 10;
      a[j] %= 10;
      a[0] += (j == a[0]);
    }
  }

  for (int i = a[0]; i > 0; i--) {
    res += a[i];
  }

  printf("\n\n%lld\n", res);

  return 0;
}
