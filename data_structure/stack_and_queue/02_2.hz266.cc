#include <cmath>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int priority(char op) {
  switch (op) {
  case '+':
  case '-':
    return 1;
  case '*':
  case '/':
    return 2;
  case '^':
    return 3;
  default:
    return 0;
  }
}

bool is_op(char c) {
  return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

bool is_num(string x) {
  if (x.size() > 1)
    return true;
  return x[0] >= '0' && x[0] <= '9';
}

void infixToPostfix(const vector<string> &s, vector<string> &postfix) {
  stack<string> op_stk;
  for (string x : s) {
    if (is_num(x)) {
      postfix.push_back(x);
    } else {
      if (x == "(") {
        op_stk.push(x);
      } else if (x == ")") {
        while (!op_stk.empty() && op_stk.top() != "(") {
          postfix.push_back(op_stk.top());
          op_stk.pop();
        }
        op_stk.pop(); // pop (;
      } else {
        while (!op_stk.empty() && priority(op_stk.top()[0]) >= priority(x[0])) {
          postfix.push_back(op_stk.top());
          op_stk.pop();
        }
        op_stk.push(x);
      }
    }
  }

  while (!op_stk.empty()) {
    if (op_stk.top() != "(" && op_stk.top() != ")")
      postfix.push_back(op_stk.top());
    op_stk.pop();
  }
}

void stringToInfix(const string &s, vector<string> &infix) {
  string num = "";
  for (int i = 0; s[i]; i++) {
    if ((s[i] == '+' || s[i] == '-') &&
        (i == 0 || is_op(s[i - 1]) || s[i - 1] == '(')) {
      num += s[i];
    } else if (s[i] >= '0' && s[i] <= '9') {
      num += s[i];
    } else {
      if (num != "")
        infix.push_back(num);
      infix.push_back(string(1, s[i]));
      num = "";
    }
  }
  if (num != "") {
    infix.push_back(num);
  }
  return;
}

long long calc(vector<string> &postfix) {
  stack<long long> s;
  for (string x : postfix) {
    if (is_num(x)) {
      s.push(stoll(x));
    } else {
      long long b = s.top();
      s.pop();
      long long a = s.top();
      s.pop();
      long long c;
      if (x == "+")
        c = a + b;
      if (x == "-")
        c = a - b;
      if (x == "*")
        c = a * b;
      if (x == "/")
        c = a / b;
      if (x == "^")
        c = pow(a, b);
      s.push(c);
    }
  }
  return s.top();
}
#ifdef DEBUG
void out(vector<string> s) {
  for (auto x : s) {
    cout << x << " ";
  }
  cout << endl;
}
#endif // DEBUG
int main() {
  string expression;
  cin >> expression;
  vector<string> infix;
  vector<string> postfix;
  stringToInfix(expression, infix);
  infixToPostfix(infix, postfix);

#ifdef DEBUG
  cout << "infix: size is: " << infix.size() << endl;
  out(infix);
  cout << "postfix: size is: " << postfix.size() << endl;
  out(postfix);
#endif // DEBUG

  long long res = calc(postfix);
  cout << res << endl;
  return 0;
}
