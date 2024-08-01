#include <stdio.h>

int main() {
  int a;
  scanf("%d", &a);
  int n = printf("%d\n", a);
  printf("count: %d\n", n - 1);
  return 0;
}
