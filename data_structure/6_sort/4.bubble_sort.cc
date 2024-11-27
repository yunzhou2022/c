#include "0.test.h"

void bubble_sort(int *data, int l, int r) {
  for (int i = r - 1, count; i > l; i--) {
    count = 0;
    for (int j = l; j < i; j++) {
      if (data[j] > data[j + 1]) {
        swap(data[j], data[j + 1]);
        ++count;
      }
    }
    if (count == 0) {
      return;
    }
  }
}

int main() {
  int *data = getRandomData(SMALL_DATA);

  TEST(bubble_sort, data, 0, SMALL_DATA);
  return 0;
}
