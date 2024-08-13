#include <math.h>
#include <stdio.h>

int main() {
  int res = 0;
  for (int i = 1; i <= 9999; i++) {
    int len = 0;
    int arr[10] = {0};

    for (int j = 1; j <= 9; j++) {
      int k = i * j;
      int lenK = log10(k) + 1;
      len += lenK;
      if (len > 9)
        break;
      int flag = 0;
      while (k) {
        if (arr[k % 10]) {
          flag = 1;
          break;
        }
        arr[k % 10] = 1;
        k /= 10;
      }
      if (flag)
        break;

      if (len == 9 && !arr[0]) {
        int temp = 0;
        for (int k = 1; k <= j; k++) {
          printf("%d x %d = %d\n", i, k, i * k);
          temp = temp * pow(10, (int)log10(i * k) + 1) + i * k;
        }
        printf("temp = %d\n", temp);

        if (temp > res)
          res = temp;
        printf("\n\n");
      }
    }
  }

  printf("%d\n", res);
  return 0;
}
