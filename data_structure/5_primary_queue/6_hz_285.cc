#include <iostream>
#include <set>
#include <utility>
#include <vector>
using namespace std;

int main() {
  int n, m, ind = 1;
  cin >> n >> m;
  set<pair<int, int>> s;
  for (int i = 0; i < n; i++) {
    vector<int> tmp;
    for (auto x : s) {
      tmp.push_back(-x.first);
    }
    s.clear();
    for (int j = 0; j < m; j++) {
      int t;
      cin >> t;
      if (tmp.size() < m) {
        s.insert({-t, ind++});
        continue;
      }
      for (auto x : tmp) {
        if (s.size() < m || -s.begin()->first > t + x) {
          s.insert({-t - x, ind++});
        }
        if (s.size() > m) {
          s.erase(s.begin());
        }
      }
    }
  }
  for (auto iter = s.rbegin(); iter != s.rend(); iter++) {
    if (iter == s.rbegin())
      cout << -iter->first;
    else
      cout << " " << -iter->first;
  }
  cout << endl;

  return 0;
}
