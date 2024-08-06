#include <stdio.h>

int isValid(int i, int base) {
  int x = i;
  int sum1[100];
  int j = 0;
  while (x) {
    sum1[j] = x % base;
    x /= base;
    j++;
  }

  for (i = 0, j = j - 1; i < j; i++, j--) {
    if (sum1[i] != sum1[j])
      return 0;
  }
  return 1;
}

void printBinary(int num) {
  int arr[100];
  int j = 0;
  while (num) {
    arr[j] = num % 2;
    num /= 2;
    j++;
  }
  for (int i = 0; i < j; i++) {
    printf("%d", arr[i]);
  }

  printf("\n");
}

int main() {
  int sum = 0;
  for (int i = 1; i < 1000000; i++) {
    if (!isValid(i, 10) || !isValid(i, 2))
      continue;
    printf("x = %d   ", i);
    printBinary(i);
    sum += i;
  }
  printf("%d\n", sum);
  return 0;
}
