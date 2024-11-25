class KthLargest {
public:
  set<pair<int, int>> s;
  k;
  i;
  KthLargest(int k, vector<int> &nums) {
    i = 0;
    this->k = k;
    for (auto x : nums) {
      add(x);
    }
  }

  int add(int val) {
    if (s.size() < k) {
      s.insert({val, ++i});
      return s.begin().first;
    }
    int top = s.begin().first;
    if (val <= top)
      return top;
    s.erase(s.begin());
    s.insert({val, ++i});
    return s.begin().first;
  }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
