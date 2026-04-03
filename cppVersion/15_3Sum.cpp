#include <algorithm>
#include <iostream>
#include <ranges>
#include <unordered_set>
#include <vector>

using namespace std;
class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> rst;
    for (int i = 1; i < nums.size() - 1; i++) {
      int l = 0, r = nums.size() - 1, target = 0 - nums[i];
      if (i && nums[i] == nums[i - 1])
        continue;
      while (l < i && i < r) {
        if (nums[l] + nums[r] > target)
          r--;
        else if (nums[l] + nums[r] < target)
          l++;
        else {
          rst.push_back({nums[l], nums[r], nums[i]});
          l++;
          r--;
          while (l < i && nums[l] == nums[l - 1])
            l++;
        }
      }
    }

    return rst;
  }
};

int main() {
  Solution s;
  vector<int> v = {-1, 0, 1, 2, -1, -4};
  vector<vector<int>> r = s.threeSum(v);
  for (const auto &row : r) {
    for (const auto &elem : row) {
      cout << elem << " ";
    }
    cout << endl;
  }
}
