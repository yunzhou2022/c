#include "0.test.h"

void selection_sort(int *data, int l, int r) {
  for (int i = l; i < r - 1; i++) {
    int k = i;
    for (int j = i + 1; j < r; j++) {
      if (data[j] < data[k])
        k = j;
    }
    swap(data[k], data[i]);
  }
}

int main() {
  int *data = getRandomData(SMALL_DATA);

  TEST(selection_sort, data, 0, SMALL_DATA);
  return 0;
}
