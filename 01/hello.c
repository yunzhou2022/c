#include <stdio.h>

int main() {
  // printf("hello world!\n");
  // printf("sizeof l %ld\n", sizeof(long));
  // printf("sizeof int %ld\n", sizeof(int));
  //  printf("sizeof longlong %ld\n", sizeof(long long));
  char hello = 'a';
  int count = printf("%d\n", hello);
  printf("count: %d\n", count);
  return 0;
}
