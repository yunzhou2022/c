#include <stdio.h>

#ifdef FFLUSH
int main() {
  int a, b;
  char c;
  scanf("%d%d", &a, &b);
  fflush(stdin);
  scanf("%c", &c);
  printf("%d %d\n", a, b);
  printf("%c\n", c);
  return 0;
}
#endif

#ifdef GETCHAR
int main() {
  int a, b;
  char c;
  scanf("%d%d", &a, &b);
  getchar();
  scanf("%c", &c);
  printf("%d %d\n", a, b);
  printf("%c\n", c);
  return 0;
}
#endif
