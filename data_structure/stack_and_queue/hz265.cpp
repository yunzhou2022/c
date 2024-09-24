#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int match[10005] = {0};

int main() {
  stack<int> s;
  string str; // = "({({(({()}})}{())})})[){{{([)()((()]]}])[{)]}{[}{)";
  cin >> str;
  for (int i = 0; str[i]; i++) {
    switch (str[i]) {
    case '(':
    case '[':
    case '{':
      s.push(i);
      break;
    case ')':
      if (s.empty() || str[s.top()] != '(')
        s.push(i);
      else {
        match[i] = str[s.top()];
        match[s.top()] = i;
        s.pop();
      }
      break;
    case '}':
      if (s.empty() || s.top() != '{') {
        s.push(i);
      } else {
        s.pop();
        match[s.top()] = i;
        match[i] = s.top();
      }
      break;
    case ']':
      if (s.empty() || s.top() != '[') {
        s.push(i);
      } else {
        s.pop();
        match[s.top()] = i;
        match[i] = s.top();
      }
      break;
    }
  }

  int i = 0, max = 0, temp_max = 0;

  while (str[i]) {
    if (match[i] != 0) {
      temp_max += match[i] - i + 1;
      i = match[i] + 1;
      if (temp_max > max) {
        max = temp_max;
      }
    } else {
      temp_max = 0;
      i++;
    }
  }

  cout << max << endl;

  return 0;
}
