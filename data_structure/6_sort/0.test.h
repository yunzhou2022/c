#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
using namespace std;

bool check(int *data, int l, int r) {
  for (int i = l + 1; i < r; i++) {
    if (data[i] < data[i - 1])
      return false;
  }
  return true;
}

#define swap(a, b)                                                             \
  {                                                                            \
    __typeof(a) __c = a;                                                       \
    a = b, b = __c;                                                            \
  }

#define TEST(func, data, start, end)                                           \
  {                                                                            \
    cout << "start test " << #func << endl;                                    \
    int n = end - start;                                                       \
    int *tmp = (int *)malloc(sizeof(int) * n);                                 \
    memcpy(tmp, data, sizeof(int) * n);                                        \
    long long b = clock();                                                     \
    func(tmp, start, end);                                                     \
    long long e = clock();                                                     \
    if (check(tmp, start, end))                                                \
      cout << "OK" << endl;                                                    \
    else                                                                       \
      cout << "FAIL" << endl;                                                  \
    cout << #func << " " << n << " items cost "                                \
         << (e - b) * 1000 / CLOCKS_PER_SEC << endl;                           \
    free(tmp);                                                                 \
  }

#define SMALL_DATA 5000
#define BIG_DATA 100000

__attribute__((constructor)) void __initRand() { srand(time(0)); }

int *getRandomData(int n) {
  int *res = (int *)malloc(sizeof(int) * n);
  for (int i = 0; i < n; i++) {
    res[i] = rand() % 100000;
  }
  return res;
}
