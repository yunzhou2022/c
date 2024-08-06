#include <stdio.h>

#define max 2540160

int fac[10] = {1};
__attribute__((constructor)) void init() {
  for (int i = 1; i < 10; i++) {
    fac[i] = fac[i - 1] * i;
  }
}

int isValid(int i) {
  int x = i;
  int sum = 0;
  while (x) {
    sum += fac[x % 10];
    x /= 10;
  }

  return sum == i;
}

int main() {
  int sum = 0;
  for (int i = 3; i < max; i++) {
    if (!isValid(i))
      continue;
    printf("x = %d   %x\n", i, i);
    sum += i;
  }

  printf("%d\n", sum);
  return 0;
}
