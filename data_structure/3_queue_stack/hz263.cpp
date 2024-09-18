#include <iostream>
#include <stack>
using namespace std;

int vis[100] = {0};
int temp[100] = {0};
int len = 0;
int tempres[1000][100];
void f(int i, int s, int n) {
  if (i == n) {
    for (int k = 0; k < n; k++) {
      tempres[len][k] = temp[k];
    }
    len++;
    return;
  }
  for (int j = s; j <= n; j++) {
    if (vis[j])
      continue;
    vis[j] = 1;
    temp[i] = j;
    f(i + 1, s, n);
    vis[j] = 0;
  }
}

bool isvalid(int *a, int n) {
  stack<int> s;
  int x = 1;
  for (int i = 0; i < n; i++) {
    if (s.empty() || s.top() < a[i]) {
      while (x <= a[i])
        s.push(x), x += 1;
    }
    if (s.empty() || s.top() != a[i])
      return false;
    s.pop();
  }
  return true;
}
int main() {
  int n;
  cin >> n;
  f(0, 1, n);
  for (int i = 0, j = 0; i < len && j < 20; i++) {
    if (isvalid(tempres[i], n)) {
      for (int k = 0; k < n; k++) {
        if (k)
          cout << ' ';
        cout << tempres[i][k];
        j++;
      }
      cout << endl;
    }
  }
  return 0;
}
