#include <stdio.h>
#include <string.h>
#define MAX_N 10000

void transform(char *s, int *a) {
  int len = strlen(s);
  a[0] = len;
  for (int i = 1; i <= len; i++) {
    a[i] = s[len - i] - '0';
  }
  return;
}

void add(int *a, int *b, int *res) {
  res[0] = a[0] > b[0] ? a[0] : b[0];

  for (int i = 1; i <= res[0]; i++) {
    res[i] += a[i] + b[i];
    if (res[i] > 9) {
      res[i] -= 10;
      res[i + 1]++;
    }
  }
  if (res[res[0] + 1])
    res[0]++;

  return;
}

int main() {

  char s1[MAX_N + 5], s2[MAX_N + 5];
  int a[MAX_N + 5] = {0}, b[MAX_N + 5] = {0}, res[MAX_N + 5] = {0};
  scanf("%s", s1);
  scanf("%s", s2);

  transform(s1, a);
  transform(s2, b);
  add(a, b, res);
  for (int i = res[0]; i > 0; i--) {
    printf("%d", res[i]);
  }

  printf("\n");

  return 0;
}
