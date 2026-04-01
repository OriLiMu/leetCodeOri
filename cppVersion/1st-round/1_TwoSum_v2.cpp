#include <algorithm>
#include <climits>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> um;
    for (int i = 0; i < nums.size(); i++) {
      auto it = um.find(target - nums[i]);
      if (it != um.end()) {
        return {it->second, i};
      } else {
        um[nums[i]] = i;
      }
    }
    return {-1, -1};
  }
};
int main() {
  Solution s;
  // vector<int> nums = {3, 2, 4};
  vector<int> nums = {3, 3};
  int target = 6;
  vector<int> r = s.twoSum(nums, target);
  cout << r[0] << r[1] << endl;
}
