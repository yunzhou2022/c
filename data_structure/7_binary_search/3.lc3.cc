#include <set>
#include <string.h>
#include <unordered_set>

using namespace std;

int lengthOfLongestSubstring(string s) {
  int res = 0;
  unordered_set<char> h;
  int l=0;
  for (auto x : s) {
    while (h.find(x) != h.end()) {
      h.erase(s[l]);
      l++;
    }
    h.insert(x);
    res = max(res, (int)h.size());
  }
  return res;
}

int main() {
  lengthOfLongestSubstring("pwwkew");
  return 0;
}