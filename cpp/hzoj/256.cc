#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Data {
  int a, b;
};

bool cmp(const Data &a, const Data &b) { return a.a * a.b < b.a * b.b; }

class BigInt : public vector<int> {
public:
  BigInt(int x) {
    push_back(x);
    process_digit();
  }

  void operator*=(int x) {
    for (int i = 0; i < size(); i++) {
      at(i) *= x;
    }
    while (size() > 1 && at(size() - 1) == 0)
      pop_back();
    process_digit();
    return;
  }

  bool operator<(const BigInt &a) {
    if (size() - a.size())
      return size() < a.size();
    for (int i = size() - 1; i >= 0; --i) {
      if (at(i) == a[i])
        continue;
      return at(i) < a[i];
    }
    return false;
  }

  void operator/=(int x) {
    int y = 0;
    for (int i = size() - 1; i >= 0; --i) {
      y = y * 10 + at(i);
      at(i) = y / x;
      y %= x;
    }
    while (size() > 1 && at(size() - 1) == 0)
      pop_back();
    process_digit();
    return;
  }

  BigInt operator/(int x) {
    BigInt ret(*this);
    ret /= x;
    return ret;
  }

private:
  void process_digit() {
    for (int i = 0; i < size(); i++) {
      if (at(i) < 10)
        continue;
      if (i + 1 == size())
        push_back(0);
      at(i + 1) += at(i) / 10;
      at(i) %= 10;
    }
  };
};

ostream &operator<<(ostream &out, const BigInt &a) {
  for (int i = a.size() - 1; i >= 0; --i) {
    out << a[i];
  }
  return out;
}

int main() {
  int n;
  cin >> n;
  vector<Data> arr;
  for (int i = 0; i <= n; i++) {
    Data temp;
    cin >> temp.a >> temp.b;
    arr.push_back(temp);
  }
  sort(arr.begin() + 1, arr.end(), cmp);
  BigInt ans = 0, sum = arr[0].a;
  for (int i = 1; i <= n; i++) {
    BigInt temp = sum / arr[i].b;
    sum *= arr[i].a;
    if (ans < temp)
      ans = temp;
  }
  cout << ans << endl;

  return 0;
}
