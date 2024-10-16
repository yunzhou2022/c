#include <cmath>
#include <iostream>
#include <string>

using namespace std;

typedef long long ll;

bool is_operator(char c) {
  return c == '(' || c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}
ll calc(string s, ll l, ll r) {
#define INF 0x7f7f7f7f
  ll pos = -1, min_pri = INF - 1, cur_pri = INF, temp_pri = 0;
  for (int i = l; i < r; i++) {
    switch (s[i]) {
    case '(':
      temp_pri += 100;
      break;
    case ')':
      temp_pri -= 100;
      break;
    case '+':
      cur_pri = 1 + temp_pri;
      break;
    case '-':
      cur_pri = 1 + temp_pri;
      break;
    case '*':
      cur_pri = 2 + temp_pri;
      break;
    case '/':
      cur_pri = 2 + temp_pri;
      break;
    case '^':
      cur_pri = 3 + temp_pri;
      break;
    }

    if ((s[i] == '+' || s[i] == '-') && (i == 0 || is_operator(s[i - 1]))) {
      cur_pri += 1000;
    }
    if (cur_pri <= min_pri) {
      min_pri = cur_pri;
      pos = i;
      cur_pri = INF;
    }
  }

  if (pos == -1) {
    ll res = 0;
    for (int i = l; i < r; i++) {
      if (s[i] < '0' || s[i] > '9')
        continue;
      res = res * 10 + (s[i] - '0');
    }
    return res;
  }

  ll a = calc(s, l, pos);
  ll b = calc(s, pos + 1, r);
  switch (s[pos]) {
  case '+':
    return a + b;
    break;
  case '-':
    return a - b;
    break;
  case '*':
    return a * b;
    break;
  case '/':
    return a / b;
    break;
  case '^':
    return pow(a, b);
    break;
  }

  return 0;
}

int main() {
  string expr;
  cin >> expr;
  ll res = calc(expr, 0, expr.size());
  cout << res << endl;
  return 0;
}
