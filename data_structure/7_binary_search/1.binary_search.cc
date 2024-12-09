#include <iostream>
using namespace std;

int f(int x) {
  int res = 0;
  if (x > 80000) {
    int tmp = x - 80000;
    x = 80000;
    res += tmp * (1 - 0.45);
  }
  if (x > 55000) {
    int tmp = x - 55000;
    x = 55000;
    res += tmp * (1 - 0.35);
  }
  if (x > 55000) {
    int tmp = x - 35000;
    x = 35000;
    res += tmp * (1 - 0.3);
  }
  if (x > 25000) {
    int tmp = x - 25000;
    x = 25000;
    res += tmp * (1 - 0.25);
  }
  if (x > 12000) {
    int tmp = x - 12000;
    x = 12000;
    res += tmp * (1 - 0.2);
  }
  if (x > 3000) {
    int tmp = x - 3000;
    x = 3000;
    res += tmp * (1 - 0.1);
  }
  if (x > 0) {
    res += x * (1 - 0.03);
  }

  return res;
}

int binary_search(int y) {
  int l = 0, r = y * 2;
  do {
    int mid = (l + r) / 2;
    int tmp = f(mid);
    if (tmp == y)
      return mid;
    if (tmp < y)
      l = mid + 1;
    else
      r = mid - 1;
  } while (l <= r);

  return -1;
}

int main() {

  int y;
  cin >> y;
  int x = binary_search(y);
  cout << x << endl;
  return 0;
}