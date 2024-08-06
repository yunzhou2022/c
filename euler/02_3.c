#include <stdio.h>

#define MAX 4000000
int main() {
  int sum = 2;
  int a = 1, b = 2;
  while (a + b < MAX) {
    a = a + b;
    b ^= a;
    a ^= b;
    b ^= a;
    if(!(b&1)){
        sum +=b;
    }
  }

  printf("%d\n", sum);
  return 0;
}
