#include <algorithm>
#include <iostream>
#include <set>
#include <utility>

using namespace std;

typedef pair<int, int> PII;

int main() {
  set<PII> s;
  int n, t = 0;
  cin >> n;
  for (int i = 0, a; i < n; i++) {
    cin >> a;
    s.insert(PII(a, t++));
  }

  int res = 0;
  for (int i = 1; i < n; i++) {
    int temp = 0;
    temp += s.begin()->first;
    s.erase(s.begin());

    temp += s.begin()->first;
    s.erase(s.begin());

    res += temp;
    s.insert(PII(temp, t++));
  }

  cout << res << endl;

  return 0;
}
