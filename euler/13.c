#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_N 50

void transform(char *s, int *a) {
  memset(a, 0, sizeof(int) * MAX_N + 5);
  int len = strlen(s);
  a[0] = len;
  for (int i = 1; i <= len; i++) {
    a[i] = s[len - i] - '0';
  }
  return;
}

void add(int *ans, int *b) {
  ans[0] = ans[0] > b[0] ? ans[0] : b[0];

  for (int i = 1; i <= ans[0]; i++) {
    ans[i] += b[i];
    if (ans[i] <= 9)
      continue;
    ans[i] -= 10;
    ans[i + 1]++;
    if (i == ans[0]) {
      ans[0]++;
    }
  }

  return;
}

int main() {

  char s1[MAX_N + 5];
  int temp[MAX_N + 5] = {0}, res[MAX_N + 5] = {0};
  for (int i = 0; i < 100; i++) {
    scanf("%s", s1);
    transform(s1, temp);
    add(res, temp);
  }

  for (int i = res[0], j = 0; j < 10; j++, i--) {
    printf("%d", res[i]);
  }

  printf("\n");

  return 0;
}
