#include "0.test.h"

void quick_sort(int *data, int l, int r) {
  if (r - l <= 1)
    return;

  int z = data[l], x = l, y = r - 1;
  do {
    while (data[x] < z)
      ++x;
    while (data[y] > z)
      --y;
    if (x <= y) {
      swap(data[x], data[y]);
      ++x;
      --y;
    }
  } while (x <= y);

  quick_sort(data, l, x);
  quick_sort(data, x, r);
}

void quick_sort_1(int *data, int l, int r) {
  if (r - l <= 1)
    return;

  while (l < r) {
    int z = data[l], x = l, y = r - 1;
    do {
      while (data[x] < z)
        ++x;
      while (data[y] > z)
        --y;
      if (x <= y) {
        swap(data[x], data[y]);
        ++x;
        --y;
      }
    } while (x <= y);

    quick_sort(data, l, x);
    l = x;
  }
}

int main() {
  int *data = getRandomData(BIG_DATA);

  //  TEST(quick_sort, data, 0, BIG_DATA);
  TEST(quick_sort_1, data, 0, BIG_DATA);
  return 0;
}
