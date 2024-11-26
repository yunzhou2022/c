#include "0.test.h"

void insert_sort(int *data, int l, int r) {
  ////  for (int i = l; i < r; i++) {
  ////    for (int j = i + 1; j > l; j--) {
  ////      if (data[j] < data[j - 1])
  ////        swap(data[j], data[j - 1]);
  ////    }
  ////  }
  for (int i = l + 1; i < r; i++) {
    int j = i;
    while (j > l && data[j] < data[j - 1]) {
      swap(data[j], data[j - 1]);
      j--;
    }
  }
}

int main() {

  int *data = getRandomData(SMALL_DATA);
  TEST(insert_sort, data, 0, SMALL_DATA)

  return 0;
}
