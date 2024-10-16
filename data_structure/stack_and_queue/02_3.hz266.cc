#include <iostream>
#include <stack>
#include <string>

using namespace std;

int getNum(const string &s, int &i) {
  int j = i + 1;
  while (s[j] >= '0' && s[j] <= '9')
    j++;
  string res = s.substr(i, j - i);
  i = j - 1;
  cout << "res: " << res << endl;
  return stoi(res);
}

int priority(const char op) {
  switch (op) {
  case '+':
    return 1;
  case '-':
    return 1;
  case '*':
    return 2;
  case '/':
    return 2;
  }
  return 0;
}

bool is_op(const char op) { return priority(op) > 0; }

int calc(int a, int b, char op) {
  switch (op) {
  case '+':
    return a + b;
  case '-':
    return a - b;
  case '*':
    return a * b;
  case '/':
    return a / b;
  }
  return 0;
}

int getRes(string s) {
  stack<int> nums;
  stack<char> ops;
  for (int i = 0; s[i]; i++) {
    if (s[i] == '(') {
      ops.push(s[i]);
      continue;
    }

    if (s[i] == ')') {
      while (!ops.empty() && priority(ops.top()) >= priority(s[i])) {
        if (ops.top() == '(') {
          ops.pop();
          break;
        }
        int b = nums.top();
        nums.pop();
        int a = nums.top();
        nums.pop();
        nums.push(calc(a, b, ops.top()));
        ops.pop();
      }
      continue;
    }

    if ((s[i] == '+' || s[i] == '-') &&
        (i == 0 || s[i - 1] == '(' || is_op(s[i - 1]))) {
      int num = getNum(s, i);
      nums.push(num);
      continue;
    }
    if (is_op(s[i])) {
      while (!ops.empty() && priority(ops.top()) >= priority(s[i])) {
        int b = nums.top();
        nums.pop();
        int a = nums.top();
        nums.pop();
        nums.push(calc(a, b, ops.top()));
        ops.pop();
      }
      ops.push(s[i]);
      continue;
    }
    int num = getNum(s, i);
    nums.push(num);
  }
  while (!ops.empty()) {
    int b = nums.top();
    nums.pop();
    int a = nums.top();
    nums.pop();
    nums.push(calc(a, b, ops.top()));
    ops.pop();
  }
  return nums.top();
}

int main() {
  string expression;
  cin >> expression;
  int res = getRes(expression);
  cout << res << endl;
  return 0;
}
