#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> arr;
  int a;
  for (int i = 0; i < n; i++) {
    cin >> a;
    arr.push_back(a);
  }
  sort(arr.begin(), arr.end());
  int p = arr[n / 2];
  int res = 0;
  for (int i = 0; i < n; i++) {
    res += abs(arr[i] - p);
  }

  cout << res << endl;
  return 0;
}
