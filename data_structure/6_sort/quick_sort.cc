#include "0.test.h"

void quick_sort(int *data, int l, int r) {
  if (r - l <= 2) {
    if (r - l <= 1)
      return;
    if (data[l] > data[l + 1]) {
      swap(data[l], data[l + 1]);
    }
    return;
  }

  int x = l, y = r - 1, z = data[l];
  do {
    while (data[y] > z)
      --y;
    while (data[x] < z)
      ++x;
    if (x <= y) {
      swap(data[x], data[y]);
      ++x;
      --y;
    }
  } while (x <= y);

  quick_sort(data, l, x);
  quick_sort(data, x, r);
}

int main() {
  int *data = getRandomData(BIG_DATA);
  TEST(quick_sort, data, 0, BIG_DATA);

  return 0;
}
