#include <stdio.h>

int main() {
  char s[100], t[100];
  scanf("%[^\n]", s);
  int n = snprintf(t, sizeof(s), "| %s |", s);

  for (int i = 0; i < n; i++) {
    printf("-");
  }
  printf("\n%s\n", t);
  for (int i = 0; i < n; i++) {
    printf("-");
  }

  return 0;
}
