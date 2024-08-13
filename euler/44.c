#include <math.h>
#include <stdio.h>

#define MAX_N 1000

int p[MAX_N + 5] = {0};

int isValid(int n) {
  for (int i = 1; i < MAX_N; i++) {
    if (n < p[i])
      return 0;
    if (n == p[i])
      return 1;
  }
  return 0;
}

int main() {
  for (int i = 1; i <= MAX_N; i++) {
    p[i] = i * (3 * i - 1) / 2;
  }

  int res = 9999;
  for (int i = 1; i < MAX_N; i++) {
    for (int j = i + 1; j <= MAX_N; j++) {
      if (!isValid(p[j] - p[i]) || !isValid(p[j] + p[i]))
        continue;
      int temp = p[j] - p[i];
      if (temp < res)
        res = temp;
    }
  }

  printf("%d\n", res);

  return 0;
}
