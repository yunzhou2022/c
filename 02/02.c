#include <stdio.h>

int main() {
  char temp[10];
  for (int i = 0; i < 10; i++) {
    temp[i] = -1;
  }
  scanf("%s", temp);
  for (int i = 0; i < 10; i++) {
    printf("%d ", temp[i]);
  }
  // char s[100];
  // scanf("%[^\n]", s);
  // printf("%s\n", s);
  return 0;
}
