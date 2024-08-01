/**
 * @author      : yz
 * @file        : 04_palindrome
 * @created     : Monday Jul 22, 2024 04:48:46 UTC
 */

#include <stdio.h>

int isPalindrome(int num) {
  int a, b;
  a = num;
  b = 0;
  while (a) {
    b = b * 10 + a % 10;
    a = a / 10;
  }
  return b == num;
}
int main() {
  int n;
  scanf("%d", &n);
  int count = 0;
  while (n) {
    count += isPalindrome(n);
    n--;
  }
  printf("%d\n", count);
  return 0;
}
