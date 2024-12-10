#include <algorithm>
#include <iostream>
using namespace std;

#define MAX 10000

#define PII pair<int, int>

PII arr[MAX + 5];

int checkY(int l, int r, int c, int len) {
  int tmp[r - l + 1];
  int cnt = 0;
  for (int i = l; i <= r; i++)
    tmp[cnt++] = arr[i].second;
  sort(tmp, tmp + cnt);

  for (int i = c - 1; i < cnt; i++) {
    if (tmp[i] - tmp[i - c + 1] < len)
      return 1;
  }
  return 0;
}

int check(int l, int c, int n) {
  int j = 0;
  for (int i = 0; i < n; i++) {
    while (arr[i].first - arr[j].first >= l)
      j++;
    if (i - j + 1 < c)
      continue;
    if (checkY(j, i, c, n))
      return 1;
  }
  return 0;
}

int main() {
  int c, n;
  cin >> c >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i].first >> arr[i].second;
  }

  sort(arr, arr + n, [&](PII a, PII b) -> bool {
    if (a.first != b.first)
      return a.first < b.first;
    return a.second < b.second;
  });

  int l = 1, r = MAX;
  while (l < r) {
    int mid = (l + r) / 2;
    if (check(mid, c, n)) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }

  cout << l << endl;

  return 0;
}
