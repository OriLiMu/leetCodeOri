#include <algorithm>
#include <climits>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
class Solution {
public:
  int searchInsert(vector<int> &nums, int target) {
    int l = 0, r = nums.size() - 1, mid, ans;
    while (l <= r) {
      mid = (l + r) / 2;
      if (nums[mid] < target) {
        l = mid + 1;
        ans = l;
      } else if (nums[mid] > target) {
        r = mid - 1;
        ans = mid;
      } else {
        return mid;
      }
    }

    return ans;
  }
};
int main() {
  Solution s;
  vector<int> v = {1, 3, 5, 6};
  v = {1, 3, 5, 6};
  s.searchInsert(v, 7);
}
