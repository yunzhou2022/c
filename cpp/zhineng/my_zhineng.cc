#include <iostream>
#include <memory>

using namespace std;

class A {
public:
  A() { cout << "contructor" << endl; }
  ~A() { cout << "destructor" << endl; }
  int x, y;
};

namespace test {

class ptr_data {
public:
  ptr_data(A *ptr, int *cnt = nullptr) : ptr(ptr), cnt(cnt) {
    if (this->cnt == nullptr) {
      this->cnt = new int(1);
    }
  }

  void increase() {
    (*cnt)++;
    return;
  }
  void decrease() {
    (*cnt)--;

    if (*cnt == 0)
      delete ptr;
    return;
  }

  bool operator==(const ptr_data &x) const {
    return x.cnt == cnt && x.ptr == ptr;
  }

  A *ptr;
  int *cnt;
};

class shared_ptr {
public:
  shared_ptr(A *ptr) : p(ptr) {}
  shared_ptr(const shared_ptr &p) : p(p.p) { this->p.increase(); }
  ~shared_ptr() { p.decrease(); }
  int use_count() { return *(p.cnt); }

  A *operator->() { return p.ptr; }
  shared_ptr &operator=(const shared_ptr &obj) {
    if (obj.p == p)
      return *this;
    p.decrease();
    p = obj.p;
    p.increase();
    return *this;
  }

private:
  ptr_data p;
};

shared_ptr make_shared() { return shared_ptr(new A()); }

int main() {
  shared_ptr p = make_shared();
  p->x = 3;
  p->y = 4;
  cout << p.use_count() << endl;
  shared_ptr q = p;
  cout << p.use_count() << endl;
  cout << q.use_count() << endl;
  p = nullptr;
  cout << q.use_count() << endl;
  q = nullptr;
  return 0;
}
} // namespace test
//

namespace test1 {
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
} // namespace test1

int main() { test::main(); }
