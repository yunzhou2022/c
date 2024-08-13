#include <stdio.h>

int n;
int f(int i) {
  if (i == n)
    return 1;
  return (f(i + 1) + 1) * 2;
}
int main() {
  scanf("%d", &n);
  printf("%d\n", f(1));
  return 0;
}
