#include <iostream>
#include <string>

using namespace std;

int main() {
  string s;
  cin >> s;
  cout << min((int)s.size(), 100) << endl;
  int pos;
  cin >> pos;
  string x;
  cin >> x;
  s.insert(pos - 1, x);
  cout << s << endl;

  cout << s.size() - s.rfind("x") << endl;

  return 0;
}
