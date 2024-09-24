#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <stack>
#include <vector>
using namespace std;

bool isValid(int *a, int n)
{
  stack<int> s;
  int i = 0;
  for (int j = 1; j <= n; j++)
  {
    s.push(j);
    while (!s.empty() && s.top() == a[i])
      i++, s.pop();
  }
  return s.empty();
}

int main()
{
  int n;
  int a[25], cnt = 20;
  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    a[i - 1] = i;
  }
  do
  {
    if (isValid(a, n))
    {
      for (int i = 0; i < n; i++)
      {
        cout << a[i];
      }
      cout << endl;
      cnt--;
    }
  } while (next_permutation(a, a + n) && cnt);

  return 0;
}
