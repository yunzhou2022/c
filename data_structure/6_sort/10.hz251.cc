#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> x, y;
  int count = n;
  while (count--) {
    int a, b;
    cin >> a >> b;
    x.push_back(a);
    y.push_back(b);
  }
  sort(x.begin(), x.end());
  for (int i = 0; i < n; i++) {
    x[i] = x[i] - i;
  }
  sort(x.begin(), x.end());
  sort(y.begin(), y.end());
  int xcost = 0, ycost = 0;
  int xtarget = x[n / 2];
  int ytarget = y[n / 2];
  for (int i = 0; i < n; i++) {
    xcost += abs(x[i] - xtarget);
  }
  for (int i = 0; i < n; i++) {
    ycost += abs(y[i] - ytarget);
  }

  cout << xcost + ycost << endl;

  return 0;
}
