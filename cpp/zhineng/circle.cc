#include <iostream>
#include <memory>

using namespace std;

class B;
class A;

class A {
public:
  A() { cout << "A contructor" << endl; }
  ~A() { cout << "A destructor" << endl; }
  shared_ptr<B> b;
};

class B {
public:
  B() { cout << "B contructor" << endl; }
  ~B() { cout << "B destructor" << endl; }
  shared_ptr<A> a;
};

int main() {
  shared_ptr<A> a = make_shared<A>();
  shared_ptr<B> b = make_shared<B>();
  cout << a.use_count() << endl;
  cout << b.use_count() << endl;
  a->b = b;
  b->a = a;
  cout << a.use_count() << endl;
  cout << b.use_count() << endl;
  a = nullptr;
  b = nullptr;
  cout << b.use_count() << endl;
  return 0;
}
