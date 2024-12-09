#include <iostream>
#include <vector>
using namespace std;

long long merge_sort(vector<int> &data, int l, int r) {
  if (r - l <= 1)
    return 0;
  int mid = (l + r) / 2;
  long long a = merge_sort(data, l, mid);
  long long b = merge_sort(data, mid, r);
  long long c = 0;
  vector<int> tmp(r - l);
  int i = l, j = mid, k = 0;
  while (i < mid || j < r) {
    if (j == r || (i < mid && data[i] <= data[j])) {
      tmp[k++] = data[i++];
    } else {
      tmp[k++] = data[j++];
      c += (mid - i);
    }
  }

  for (int i = l; i < r; i++) {
    data[i] = tmp[i - l];
  }

  return a + b + c;
}

int main() {
  int n;
  while (1) {
    cin >> n;
    if (n == 0)
      break;
    vector<int> data(n);
    for (int i = 0; i < n; i++) {
      cin >> data[i];
    }
    long long res = merge_sort(data, 0, n);
    cout << res << endl;
  }
  return 0;
}
