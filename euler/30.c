#include <math.h>
#include <stdio.h>

int isValid(int n) {
  int sum = 0;
  int x = n;
  while (x) {
    sum += pow(x % 10, 5);
    x /= 10;
  }
  return n == sum;
}

int main() {
  int sum = 0;
  int max = pow(9,5)*6;
  for (int i = 10; i <= max; i++) {
    if (!isValid(i))
      continue;
    printf("x = %d\n", i);
    sum += i;
  }

  printf("%d\n", sum);
  return 0;
}
