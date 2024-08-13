#include <iostream>
using namespace std;
#define N 15

int arr[N + 5][N + 5];
int f[N + 5][N + 5];

int main() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= i; j++) {
      cin >> arr[i][j];
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= i; j++) {
      cout << arr[i][j];
    }
    cout << endl;
  }

  for (int i = N - 2; i >= 0; i--) {
    for (int j = i; j >= 0; j--) {
      arr[i][j] = max(arr[i + 1][j], arr[i + 1][j + 1]) + arr[i][j];
    }
  }

  printf("%d\n", arr[0][0]);

  return 0;
}
