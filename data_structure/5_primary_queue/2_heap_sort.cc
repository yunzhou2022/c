#include <cstdlib>
#include <iostream>
using namespace std;

#define parent(i) ((i) / 2)
#define lchild(i) ((i) * 2)
#define rchild(i) ((i) * 2 + 1)
#define cmp <
#define swap(a, b)                                                             \
  {                                                                            \
    __typeof(a) __c = (b);                                                     \
    (b) = (a);                                                                 \
    (a) = __c;                                                                 \
  }

void up_update(int *data, int n) {
  int i = n;
  while (i > 0 && data[i] cmp data[parent(i)]) {
    swap(data[i], data[parent(i)]);
    i = parent(i);
  }
  return;
}

void down_update(int *data, int i, int n) {
  while (lchild(i) <= n) {
    int ind = i, l = lchild(i), r = rchild(i);
    if (data[l] cmp data[ind])
      ind = l;
    if (r <= n && data[r] cmp data[ind])
      ind = r;
    if (ind == i)
      break;
    swap(data[ind], data[i]);
    i = ind;
  }
  return;
}

void head_sort_final(int *data, int n) {
  for (int i = n; i >= 2; i--) {
    swap(data[1], data[i]);
    down_update(data, 1, i - 1);
  }
}

void normal_heap(int *data, int n) {
  for (int i = 2; i <= n; i++) {
    up_update(data, i);
  }
}

void linner_heap(int *data, int n) {
  for (int i = n / 2; i >= 1; i--) {
    down_update(data, i, n);
  }
  return;
}

int main() {
  srand(time(0));
#define MAX_N 5
  int n = MAX_N;
  int *_arr = (int *)malloc(sizeof(int) * MAX_N);
  int *arr = _arr - 1;
  for (int i = 1; i <= n; i++) {
    arr[i] = rand() % 10;
  }

  //   normal_heap(arr, n);
  linner_heap(arr, n);

  head_sort_final(arr, n);
  for (int i = 1; i <= n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;

  return 0;
}
