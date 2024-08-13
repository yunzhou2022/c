#include <iostream>

using namespace std;

int f(int *arr, int i, int n) {
  if (arr[i] + i >= n)
    return 1;
  return f(arr, i + arr[i], n) + 1;
}

int main() {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  cout << f(arr, 0, n) << endl;
  return 0;
}
