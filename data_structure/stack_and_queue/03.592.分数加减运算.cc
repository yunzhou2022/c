#include <cstdlib>
#include <iostream>
#include <string>
#include <utility>

using namespace std;
typedef pair<int, int> PII;

int gcd(int a, int b) { return a == 0 ? b : gcd(b, a % b); }
PII parse(string a) {
  int i = 1;
  while (a[i] != '/')
    i++;
  int pa = stoi(a.substr(1, i - 1));
  int pb = stoi(a.substr(i + 1, a.size() - i));
  cout << "pa: " << pa << " pb: " << pb << endl;
  return PII(pa, pb);
}

string calc(string a, string b) {
  bool sa = a[0] == '+', sb = b[0] == '+';
  if (!sa && sb)
    return calc(b, a);
  PII pa = parse(a), pb = parse(b);
  int qa1 = pa.first, qa2 = pa.second, qb1 = pb.first, qb2 = pb.second;
  int rate_a = qb2, rate_b = qa2;
  qa1 *= rate_a;
  qa2 *= rate_a;
  qb1 *= rate_b;
  qb2 *= rate_b;

  if (sa && sb) {
    qa1 += qb1;
    int common_divider = gcd(qa1, qa2);
    qa1 /= common_divider;
    qa2 /= common_divider;
    return '+' + to_string(qa1) + '/' + to_string(qa2);
  }
  if (!sa && !sb) {
    qa1 += qb1;
    int common_divider = gcd(qa1, qa2);
    qa1 /= common_divider;
    qa2 /= common_divider;
    return '-' + to_string(qa1) + '/' + to_string(qa2);
  }
  qa1 -= qb1;
  int common_divider = gcd(abs(qa1), qa2);
  qa1 /= common_divider;
  qa2 /= common_divider;
  string signal = qa1 < 0 ? "" : "+";
  return signal + to_string(qa1) + '/' + to_string(qa2);
}

string getRes(const string &s) {
  string res = "";
  for (int i = 0; s[i];) {
    int j = i + 1;
    while (s[j] && s[j] != '+' && s[j] != '-')
      j++;
    string num = s.substr(i, j - i);
    cout << "num: " << num << endl;
    if (num[0] != '+' && num[0] != '-')
      num = '+' + num;
    if (res == "")
      res = num;
    else
      res = calc(res, num);
    i = j;
  }

  return res;
}

int main() {
  string s;
  cin >> s;
  string res = getRes(s);
  cout << res << endl;
  return 0;
}
