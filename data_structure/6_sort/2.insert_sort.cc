#include "0.test.h"

void insert_sort(int *data, int l, int r) {
  for (int i = l + 1; i < r; i++) {
    int j = i;
    while (j > l && data[j] < data[j - 1]) {
      swap(data[j], data[j - 1]);
      j--;
    }
  }
}

void insert_sort2(int *data, int l, int r) {
  int i = l;
  while (i + 1 < r) {
    if (data[i + 1] < data[i]) {
      int j = i + 1;
      while (j > l && data[j] < data[j - 1]) {
        swap(data[j], data[j - 1]);
        j--;
      }
    }
    i++;
  }
}

int main() {

  int *data = getRandomData(SMALL_DATA);
  TEST(insert_sort2, data, 0, SMALL_DATA)

  return 0;
}
