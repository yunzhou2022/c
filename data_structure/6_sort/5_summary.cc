#include "0.test.h"

void selection_sort(int *data, int l, int r) {
  for (int i = l; i < r; i++) {
    int ind = i;
    for (int j = i + 1; j < r; j++) {
      if (data[j] < data[ind])
        ind = j;
    }

    swap(data[ind], data[i]);
  }
}

void insert_sort(int *data, int l, int r) {
  for (int i = l + 1; i < r; i++) {
    int ind = i;
    while (ind > l && data[ind] < data[ind - 1])
      swap(data[ind], data[ind - 1]);
  }
}

void bubble_sort(int *data, int l, int r) {
  int count;
  for (int i = r - 1; i > l; i--) {
    count = 0;
    for (int j = l; j < i; j++) {
      if (data[j] > data[j + 1]) {
        swap(data[j], data[j + 1]);
        ++count;
      }
    }
    if (count == 0)
      return;
  }
}

int main() {
  int *data = getRandomData(SMALL_DATA);

  TEST(bubble_sort, data, 0, SMALL_DATA);
  TEST(insert_sort, data, 0, SMALL_DATA);
  TEST(selection_sort, data, 0, SMALL_DATA);
  return 0;
}
