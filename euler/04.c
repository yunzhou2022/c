#include <stdio.h>

int isPrime(int x) {
  int n = x, a = 0;
  while (n) {
    a = a * 10 + n % 10;
    n = n / 10;
  }
  return a == x;
}

int main() {
  int max = 0;
  for (int i = 100; i < 1000; i++) {
    for (int j = 100; j < 1000; j++) {
      int temp = i * j;
      if (isPrime(temp) && temp>max) {
        max = temp;
      }
    }
  }

  printf("%d\n", max);
  return 0;
}
