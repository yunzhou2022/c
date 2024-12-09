#include "0.test.h"

void merge_sort(int *data, int l, int r) {
  if (r - l <= 1)
    return;

  int mid = (l + r) >> 1;
  merge_sort(data, l, mid);
  merge_sort(data, mid, r);

  int *tmp = (int *)malloc(sizeof(int) * (r - l));
  memset(tmp, 0, sizeof(int) * (r - l));
  int i = l, j = mid, k = 0;
  while (i < mid || j < r) {
    if (j >= r || (i < mid && data[i] < data[j])) {
      tmp[k++] = data[i++];
    } else {
      tmp[k++] = data[j++];
    }
  }
  memcpy(data + l, tmp, sizeof(int) * (r - l));
}

int main() {
  int *data = getRandomData(BIG_DATA);
  TEST(merge_sort, data, 0, BIG_DATA);
  return 0;
}
