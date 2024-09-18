#include <iostream>
#include <memory>

using namespace std;

class A {
public:
  A() { cout << "contructor" << endl; }
  ~A() { cout << "destructor" << endl; }
};

int main() {
  shared_ptr<A> p = make_shared<A>();
  cout << p.use_count() << endl;
  shared_ptr<A> q = p;
  cout << p.use_count() << endl;
  cout << q.use_count() << endl;
  p = nullptr;
  cout << q.use_count() << endl;
  q = nullptr;
  return 0;
}
