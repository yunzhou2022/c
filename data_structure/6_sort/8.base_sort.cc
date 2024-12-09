#include "0.test.h"

#define K 65536
void base_sort(int *data, int l, int r) {
  int *cnt = (int *)malloc(sizeof(int) * K);
  int *temp = (int *)malloc(sizeof(int) * (r - l));

  memset(cnt, 0, sizeof(int) * K);
  for (int i = l; i < r; i++)
    cnt[data[i] % K]++;
  for (int i = 1; i < K; i++)
    cnt[i] += cnt[i - 1];
  for (int i = r - 1; i >= 0; i--) {
    temp[--cnt[data[i] % K]] = data[i];
  }
  memcpy(data, temp, sizeof(int) * (r - l));

  memset(cnt, 0, sizeof(int) * K);
  for (int i = l; i < r; i++)
    cnt[data[i] / K]++;
  for (int i = 1; i < K; i++)
    cnt[i] += cnt[i - 1];
  for (int i = r - 1; i >= 0; i--) {
    temp[--cnt[data[i] / K]] = data[i];
  }
  memcpy(data, temp, sizeof(int) * (r - l));
}

int main() {
  int *data = getRandomData(BIG_DATA);
  TEST(base_sort, data, 0, BIG_DATA);
  return 0;
}
