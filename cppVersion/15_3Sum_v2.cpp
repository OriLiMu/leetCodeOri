#include <algorithm>
#include <climits>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    // cout << endl;
    int left = 0;
    int right = nums.size() - 1;
    vector<vector<int>> r;
    int target, tmp;
    for (int i = 0; i < nums.size(); i++) {
      if (i > 0 && nums[i] == nums[i - 1]) {
        continue;
      }
      target = -1 * nums[i];
      left = i + 1;
      right = nums.size() - 1;
      // 这两个提前的判断很重要
      if (left + 1 < nums.size() - 1 && nums[left] + nums[left + 1] > target)
        break;
      while (left < right) {
        tmp = nums[left] + nums[right];
        if (nums[right] + nums[right - 1] < target)
          break;
        if (target == tmp) {
          r.push_back({nums[i], nums[left], nums[right]});
          while (left < right) {
            left++;
            if (nums[left - 1] != nums[left]) {
              break;
            }
          }
          while (left < right) {
            right--;
            if (nums[right] != nums[right + 1]) {
              break;
            }
          }
        } else if (tmp > target) {
          right--;
        } else {
          left++;
        }
      }
    }

    return r;
  }
};

int main() {
  Solution s;
  vector<int> nums = {-1, 0, 1, 2, -1, -4};
  vector<vector<int>> r = s.threeSum(nums);
  for (auto v : r) {
    for (auto n : v) {
      cout << n << ", ";
    }
    cout << endl;
  }
}
