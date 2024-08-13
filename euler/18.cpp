#include <cstdio>
#include <iostream>
using namespace std;
#define N 15

int arr[N + 5][N + 5];
int dfs(int i, int j) {
  if (i == N) {
    return 0;
  }

  return max(dfs(i + 1, j), dfs(i + 1, j + 1)) + arr[i][j];
}

int main() {

  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= i; j++) {
      scanf("%d", &arr[i][j]);
    }
  }

  printf("%d\n", dfs(0, 0));
  return 0;
}
