#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int findK(vector<int> &nums1, vector<int> &nums2, int k, int l1, int r1,
            int l2, int r2) {
    if (k == 1) {
      if (l1 > r1)
        return nums2[l2];
      if (l2 > r2)
        return nums1[l1];
      return min(nums1[l1], nums2[l2]);
    }
    int mid = k / 2;
    if (nums1[l1 + mid - 1] < nums2[l2 + mid - 1]) {
      return findK(nums1, nums2, k - mid, mid, r1, l2, r2);
    } else {
      return findK(nums1, nums2, k - mid, l1, r1, mid, r2);
    }
  }
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    int len1 = nums1.size(), len2 = nums2.size();
    int len = len1 + len2;
    int k = len / 2 + 1;
    if (len & 1) {
      return findK(nums1, nums2, k, 0, len1 - 1, 0, len2 - 1);
    }
    return (findK(nums1, nums2, k, 0, len1 - 1, 0, len2 - 1) +
            findK(nums1, nums2, k - 1, 0, len1 - 1, 0, len2 - 1)) /
           2.0;
  }
};

int main() {
  vector<int> nums1;
  nums1 = {1, 2};
  vector<int> nums2{3, 4};
  auto s = new Solution();
  double res = s->findMedianSortedArrays(nums1, nums2);
  cout << res << endl;
  return 0;
}