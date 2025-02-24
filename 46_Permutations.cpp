#include <algorithm>
#include <climits>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
  void getPermute(vector<int> &nums, int startIndex,
                  vector<vector<int>> &result) {
    if (startIndex == nums.size()) {
      result.push_back(nums);
      return;
    }
    for (int i = startIndex; i < nums.size(); i++) {
      swap(nums[i], nums[startIndex]);
      getPermute(nums, startIndex + 1, result);
      swap(nums[i], nums[startIndex]);
    }
  }
  vector<vector<int>> permute(vector<int> &nums) {
    vector<vector<int>> result;
    getPermute(nums, 0, result);
    return result;
  }
};
int main() {
  Solution s;
  vector<int> nums = {1, 2, 3};
  vector<vector<int>> r = s.permute(nums);
  for (vector<int> v : r) {
    for (int n : v) {
      cout << n;
    }
    cout << endl;
  }
}
