#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define MAX_N 1000

class BigInt : public vector<int> {
public:
  BigInt(int x) {
    this->push_back(x);
    this->process_digit();
  }

  void process_digit() {
    for (int i = 0; i < size(); i++) {
      if (at(i) < 10)
        continue;
      if (i == size() - 1)
        this->push_back(0);
      at(i + 1) += at(i) / 10;
      at(i) %= 10;
    }
    while (size() > 1 && at(size() - 1) == 0)
      this->pop_back();
  }

  void operator*=(const int &x) {
    for (int i = 0; i < size(); i++) {
      at(i) *= x;
    }

    this->process_digit();
  }

  bool operator>(const BigInt &x) {
    if (size() != x.size())
      return size() > x.size();
    for (int i = size()-1; i >= 0; i--) {
      if (at(i) != x.at(i))
        return at(i) > x.at(i);
    }
    return false;
  }

  BigInt operator/(const int &x) {
    BigInt ret(*this);
    int y = 0;
    for (int i = size() - 1; i >= 0; i--) {
      y = y * 10 + at(i);
      ret[i] = y / x;
      y %= x;
    }
    ret.process_digit();
    return ret;
  }
};

ostream &operator<<(ostream &out, const BigInt &a) {
  for (int i = a.size() - 1; i >= 0; i--) {
    out << a[i];
  }
  return out;
}

int a[MAX_N + 5], b[MAX_N + 5], c[MAX_N + 5];

int main() {
  int n;
  cin >> n;
  for (int i = 0; i <= n; i++) {
    cin >> a[i] >> b[i];
    c[i] = i;
  }

  sort(c + 1, c + n + 1,
       [&](int i, int j) { return a[i] * b[i] < a[j] * b[j]; });
  BigInt sum = a[0], res = 0, tmp = 0;
  for (int i = 1; i <= n; i++) {
    tmp = sum / b[c[i]];
    if (tmp > res)
      res = tmp;
    sum *= a[c[i]];
  }
  cout << res << endl;
  return 0;
}