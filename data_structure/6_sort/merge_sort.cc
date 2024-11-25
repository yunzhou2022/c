#include "0.test.h"

void merge_sort(int *data, int l, int r) {
  if (r - l <= 1)
    return;
  int mid = (l + r) / 2;
  merge_sort(data, l, mid);
  merge_sort(data, mid, r);

  int *temp = (int *)malloc(sizeof(int) * (r - l));
  int p1 = l, p2 = mid, k = 0;
  while (p1 < mid || p2 < r) {
    if ((p1 < mid && data[p1] < data[p2]) || p2 == r) {
      temp[k++] = data[p1++];
    } else {
      temp[k++] = data[p2++];
    }
  }

  for (int i = l; i < r; i++) {
    data[i] = temp[i - l];
  }
}

int main() {
  int *data = getRandomData(BIG_DATA);
  TEST(merge_sort, data, 0, BIG_DATA);
  return 0;
}
