#include <iostream>

using namespace std;

ostream &operator<<(ostream &ss, string s) {
  ss << s << endl;
  return ss;
}

class A {
public:
  A(int x, int y) : x(x), y(y) {}
  A &operator*=(int z) {
    x *= z;
    y *= z;
    return *this;
  }

  int x, y;
};
ostream &operator<<(ostream &out, A a) {
  return out << a.x << "," << a.y << endl;
}

int main() {
  A a(3, 4);
  (a *= 2) *= 3;

  cout << a;

  return 0;
}
