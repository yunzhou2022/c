#include <iostream>
using namespace std;

int arr[10];

void print_one_line(int n) {
  for (int i = 0; i <= n; i++) {
    if (i)
      cout << " ";
    cout << arr[i];
  }
  cout << endl;
}

void f(int i, int j, int n) {
  if (j > n)
    return;
  for (int k = j; k <= n; k++) {
    arr[i] = k;
    print_one_line(i);
    f(i + 1, k + 1, n);
  }
}

int main() {
  int n;
  cin >> n;
  f(0, 1, n);

  return 0;
}
