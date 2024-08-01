/**
 * @author      : yz
 * @file        : 6_start
 * @created     : Thursday Aug 01, 2024 14:20:58 UTC
 */

#include <stdio.h>
// #define offset(T, d)({\
        T a;\
        (void *)(&a.d) - (void*)(&a);\
        })
#define start(addr, T, d) (T *)((void *)addr - offset(T, d))
#define offset(T, d) (size_t) & (((T *)(0))->d)

typedef struct A {
  int a;
  char b;
  float c;
} A;

int main() {
  printf("%lu\n", offset(struct A, a));
  printf("%lu\n", offset(struct A, b));
  printf("%lu\n", offset(struct A, c));
  A a;
  printf("%p\n", &a);
  printf("%p\n", start(&a.a, A, a));
  printf("%p\n", start(&a.b, A, b));
  printf("%p\n", start(&a.c, A, c));

  return 0;
}
