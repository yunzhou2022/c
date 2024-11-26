#include "0.test.h"

void insert_sort(int *data, int l, int r, int step) {
  for (int i = l + step; i < r; i += step) {
    int j = i;
    while (j > l && data[j] < data[j - step]) {
      swap(data[j], data[j - step]);
      j -= step;
    }
  }
}

void shell_sort(int *data, int l, int r) {
  int n = r - l, k = 2, step;
  do {
    step = n / k == 0 ? 1 : n / k;
    for (int i = l, I = l + step; i < I; i++) {
      insert_sort(data, i, r, step);
    }
    k *= 2;
  } while (step != 1);
}

void shell_sort_hibbard(int *data, int l, int r) {
  int k = 1, n = r - l;
  while (k < n)
    k <<= 1;
  int step;
  do {
    k >>= 1;
    step = k - 1;
    if (step <= 0)
      step = 1;
    for (int i = l, I = l + step; i < I; i++) {
      insert_sort(data, l, r, step);
    }
  } while (step != 1);
}

int main() {

  int *data = getRandomData(SMALL_DATA);
  TEST(shell_sort, data, 0, SMALL_DATA)
  TEST(shell_sort_hibbard, data, 0, SMALL_DATA)

  return 0;
}
