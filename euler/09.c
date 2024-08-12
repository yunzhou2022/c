#include <stdio.h>

int main() {
  for (int a = 4; a < 500; a++) {
    for (int b = a + 1; b < 500; b++) {
      int c = 1000 - a - b;
      if (a + b <= c)
        continue;
      if (a * a + b * b != c * c)
        continue;
      printf("%d %d %d\n", a, b, c);
      printf("%d\n", a * b * c);
      return 0;
    }
  }
  return 0;
}
