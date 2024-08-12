#include <stdio.h>

int isPrime(int x, int base) {
  int n = x, a = 0;
  while (n) {
                 a = a * base + n % base;
    n = n / base;
  }
  return a == x;
}

int main() {
  int max = 0;
  for (int i = 999; i >= 100; i--) {
    for (int j = i; j >= 100; j--) {
      int temp = i * j;
      if (!(temp > max && isPrime(temp, 10)))
        continue;
      max = temp;
    }
  }

  printf("%d\n", max);
  return 0;
}
