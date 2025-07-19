#include <algorithm>
#include <climits>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
class Solution {
public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    // get first
    vector<int> result;
    int curMax = *max_element(nums.begin(), nums.begin() + k);
    result.push_back(curMax);
    for (int i = 1; i <= nums.size() - k; i++) {
      if (nums[i - 1] != curMax) {
        curMax = max(curMax, nums[i + k - 1]);
      } else {
        curMax = *max_element(nums.begin() + i, nums.begin() + i + k);
      }
      result.push_back(curMax);
    }
    return result;
  }
};
int main() {
  Solution s;
  vector<int> n = {1, 3, -1, -3, 5, 3, 6, 7};
  // vector<int> n = {1};
  int k = 3;
  for (auto n : s.maxSlidingWindow(n, k)) {
    cout << n << ", ";
  }
}
