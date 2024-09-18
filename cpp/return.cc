#include <iostream>

using namespace std;

class People {
public:
  People(string name) : name(name) { cout << "default constructor" << endl; }
  People(const People &p) {
    name = p.name;
    cout << "copy" << endl;
  }
  string name;
};

People func() {
  People temp("temp");
  return temp;
}

int main() {
  People p = func();

  return 0;
}
