#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_N 1000

void add(int *res, int *a) {
  res[0] = res[0] > a[0] ? res[0] : a[0];
  for (int i = 1; i <= res[0]; i++) {
    res[i] += a[i];
    if (res[i] < 10)
      continue;
    res[i + 1] += res[i] / 10;
    res[i] = res[i] % 10;
    res[0] += (res[0] == i);
  }
}

int fib[3][MAX_N + 5] = {{0, 0}, {1, 1}, {1, 1}};
int main() {
  int n = 2;
  while (fib[n % 3][0] < MAX_N) {
    n += 1;
    int *a = fib[n % 3], *b = fib[(n - 1) % 3], *c = fib[(n - 2) % 3];
    memset(a, 0, sizeof(int) * (MAX_N + 5));
    add(a, b);
    add(a, c);
    //    for (int i = 1; i <= b[0]; i++) {
    //      a[i] = b[i] + c[i];
    //    }
    //    a[0] = b[0];
    //    for (int i = 1; i <= a[0]; i++) {
    //      if (a[i] < 10)
    //        continue;
    //      a[i + 1] += a[i] / 10;
    //      a[i] %= 10;
    //      a[0] += (i == a[0]);
    //    }
  }

  printf("%d\n", n);

  return 0;
}
