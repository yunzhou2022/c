#include <cstdio>
#include <cstdlib>
#include <set>
#include <utility>
using namespace std;
#define MAX_N 100000

long long arr[MAX_N + 5] = {0};
int l[MAX_N + 5] = {0}, r[MAX_N + 5] = {0}, st[MAX_N + 5] = {0};

void del(int ind) {
  r[l[ind]] = r[ind];
  l[r[ind]] = l[ind];
  st[ind] = 1;
}

set<pair<int, int>> h;

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  scanf("%lld", arr + 1);
  int k = 1;
  for (int i = 1, a; i < n; i++) {
    scanf("%d", &a);
    if (1LL * a * arr[k] < 0)
      arr[++k] = a;
    else
      arr[k] += a;
  }
  long long S = 0, cnt = 0;
  n = k;
  for (int i = 1; i <= n; i++) {
    h.insert({abs(arr[i]), i});
    if (arr[i] > 0) {
      S += arr[i];
      cnt++;
    }
    l[i] = i - 1;
    r[i] = i + 1;
  }
  while (cnt > m) {
    while (st[h.begin()->second])
      h.erase(h.begin());
    int ind = h.begin()->second;
    h.erase(h.begin());
    int left = l[ind], right = r[ind];
    if ((left > 0 && right <= n) || arr[ind] > 0) {
      S -= abs(arr[ind]);
      cnt -= 1;
      arr[ind] += arr[left] + arr[right];
      h.insert({abs(arr[ind]), ind});
      del(left);
      del(right);
    }
  }

  printf("%lld\n", S);
  return 0;
}
