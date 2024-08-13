#include <math.h>
#include <stdio.h>

#define MAX_N 100000
int keep[MAX_N + 5] = {0};

int add_to_num(int x, int *arr) {
  while (x) {
    int t = x % 10;
    if (!t || arr[t])
      return 0;
    arr[t] = 1;
    x /= 10;
  }

  return 1;
}

int isValid(int a, int b, int c) {
  int arr[10] = {0};
  int flag = 1;
  flag = flag && add_to_num(a, arr);
  flag = flag && add_to_num(b, arr);
  flag = flag && add_to_num(c, arr);
  return flag;
}

int main() {
  int sum = 0;
  for (int i = 1; i < MAX_N; i++) {
    for (int j = i + 1; j <= MAX_N; j++) {
      int k = i * j;
      int lenA = log10(i) + 1;
      int lenB = log10(j) + 1;
      int lenC = log10(k) + 1;

      if (lenA + lenB + lenC < 9)
        continue;
      if (lenA + lenB + lenC > 9)
        break;

      if (!isValid(i, j, k))
        continue;
      if (keep[k])
        continue;
      keep[k] = 1;
      printf("%d * %d = %d\n", i, j, k);
      sum += k;
    }
  }

  printf("%d\n", sum);
  return 0;
}
