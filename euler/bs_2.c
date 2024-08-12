#include <stdio.h>

int bs(int y) {
  int s = 0, e = y;
  while (s <= e) {
    int mid = (s + e) >> 1;
    int temp = mid * mid * mid;
    if (temp == y)
      return mid;
    if (temp < y)
      s = mid + 1;
    if (temp > y)
      e = mid - 1;
  }
  return -1;
}
int main() {
  int y;
  while (scanf("%d", &y) != EOF) {
    int x = bs(y);
    if (x != -1)
      printf("%d ** 3 = %d\n", x, y);
    else
      printf("%d is not lifangshu \n", y);
  }
  return 0;
}
