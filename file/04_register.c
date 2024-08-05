/**
 * @author      : yz
 * @file        : 04_register
 * @created     : Saturday Aug 03, 2024 10:24:35 UTC
 */

#include <stdio.h>

int arr[10] = {0};
__attribute__((constructor())) void test0() {
  arr[0] = 99;

  printf("test0 \n");
}

__attribute__((constructor())) void test1() {
  arr[1] = 100;

  printf("test1 \n");
}

__attribute__((constructor())) void test2() {
  arr[2] = 10086;

  printf("test2 \n");
}

int main() {
  for (int i = 0; i < 10; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  return 0;
}
