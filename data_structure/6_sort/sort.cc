#include "0.test.h"

void selection_sort(int *data, int l, int r) {
  for (int i = l; i < r; i++) {
    int min = i;
    for (int j = i + 1; j < r; j++) {
      if (data[j] < data[min])
        min = j;
    }
    swap(data[min], data[i]);
  }
}

void insert_sort(int *data, int l, int r) {
  for (int i = l + 1; i < r; i++) {
    int j = i;
    while (j > l && data[j] < data[j - 1]) {
      swap(data[j], data[j - 1]);
      --j;
    }
  }
}

void bubble_sort(int *data, int l, int r) {
  for (int i = r - i; i > l; i--) {
    for (int j = l; j < i; j++) {
      if (data[j] > data[j + 1])
        swap(data[j], data[j + 1]);
    }
  }
}

void quick_sort(int *data, int l, int r) {
  if (r - l <= 1)
    return;
  int z = data[l], x = l, y = r - 1;
  while (x <= y) {
    while (data[x] < z)
      ++x;
    while (data[y] > z)
      --y;
    if (x <= y) {
      swap(data[x], data[y]);
      ++x;
      --y;
    }
  }

  quick_sort(data, l, x);
  quick_sort(data, x, r);
}

int main() {
  int *data = getRandomData(SMALL_DATA);

  TEST(selection_sort, data, 0, SMALL_DATA);
  TEST(insert_sort, data, 0, SMALL_DATA);
  TEST(bubble_sort, data, 0, SMALL_DATA);
  TEST(quick_sort, data, 0, SMALL_DATA);
  return 0;
}
