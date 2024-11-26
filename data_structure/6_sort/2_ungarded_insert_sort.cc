#include "0.test.h"

void unguarded_insert_sort(int *data, int l, int r) {
  //  int i = l + 1, min = l;
  //  while (i < r) {
  //    if (data[i] < data[min])
  //      min = i;
  //    i++;
  //  }

  int min = l;
  for (int i = l + 1; i < r; i++) {
    if (data[min] > data[i])
      min = i;
  }

  while (min > l) {
    swap(data[min], data[min - 1]);
    min--;
  }

  for (int i = l + 1; i < r; i++) {
    while (data[i] < data[i - 1]) {
      swap(data[i], data[i - 1]);
      i--;
    }
  }
}

int main() {

  int *data = getRandomData(SMALL_DATA);
  TEST(unguarded_insert_sort, data, 0, SMALL_DATA)

  return 0;
}
