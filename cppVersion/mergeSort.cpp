#include <algorithm>
#include <climits>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <iterator>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
  void merge_sort(vector<int> &nums, int l, int r, vector<int> &tmp) {
    if (l >= r)
      return;
    int mid = (l + r) / 2;
    merge_sort(nums, l, mid, tmp);
    merge_sort(nums, mid + 1, r, tmp);
    int k = l, i1 = l, i2 = mid + 1;
    while (i1 <= mid && i2 <= r)
      if (nums[i1] <= nums[i2])
        tmp[k++] = nums[i1++];
      else
        tmp[k++] = nums[i2++];
    while (i1 <= mid)
      tmp[k++] = nums[i1++];
    while (i2 <= r)
      tmp[k++] = nums[i2++];
    copy(tmp.begin() + l, tmp.begin() + r + 1, nums.begin() + l);
  }
};
int main() {

  vector<int> v1 = {2, 1, 9, 3, 10};
  Solution s;
  vector<int> r(v1.size());
  s.merge_sort(v1, 0, v1.size() - 1, r);
  for (auto n : r) {
    cout << n << ", ";
  }
  cout << endl;
}
