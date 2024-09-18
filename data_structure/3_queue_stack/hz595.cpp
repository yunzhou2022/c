#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  int N;
  cin >> N;
  vector<string> ops(N), s;
  for (int i = 0; i < N; i++)
    cin >> ops[i];
  string target;
  cin >> target;
  int flag = 0;
  for (int i = 0; i < N; i++) {
    if (ops[i] == target) {
      flag = 1;
      s.push_back(ops[i]);
      break;
    } else {
      if (ops[i] == "return") {
        s.pop_back();
      } else {
        s.push_back(ops[i]);
      }
    }
  }

  if (flag == 1) {
    for (int i = 0; i < s.size(); i++) {
      if (i)
        cout << "->";
      cout << s[i];
    }
    cout << endl;
  } else {
    cout << "NOT REFERENCED" << endl;
  }

  return 0;
}
