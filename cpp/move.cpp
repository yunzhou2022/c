#include <iostream>

using namespace std;

class A {
public:
  A() : n(10), arr(new int[n]) {
    for (int i = 0; i < n; i++) {
      arr[i] = i;
    }
  }
  A(const A &a) : n(a.n), arr(a.arr) { cout << "copy A" << std::endl; }
  A(A &&a) : n(a.n), arr(a.arr) {
    a.arr = nullptr;
    a.n = 0;
    cout << "move A" << std::endl;
  }

  void print() {
    for (int i = 0; i < n; i++) {
      cout << arr[i] << " ";
    }
    cout << endl;
  }

  int size() { return n; }

private:
  int n;
  int *arr;
};

#define TEST(exp)                                                              \
  {                                                                            \
    cout << "TEST: " << #exp << endl;                                          \
    exp;                                                                       \
    cout << endl;                                                              \
  }

int main() {
  A a, c = a;
  TEST(a.print());
  TEST(c.print());
  A b = std::move(a);
  TEST(b.print());
  TEST(cout << a.size() << endl);
  TEST(c.print());
  return 0;
}