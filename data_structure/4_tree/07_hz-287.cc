#include <iostream>
#include <set>
#include <utility>
using namespace std;

int main() {
  int n;
  cin >> n;
  int cnt = 0;
  set<pair<int, int>> s;
  int temp;
  for (int i = 0; i < n; i++) {
    cin >> temp;
    s.insert({temp, ++cnt});
  }
  int cost = 0;

  for (int i = 1; i < n; i++) {
    int a = s.begin()->first;
    s.erase(s.begin());
    int b = s.begin()->first;
    s.erase(s.begin());
    s.insert({a + b, ++cnt});
    cost += a + b;
  }
  cout << cost << endl;

  return 0;
}
