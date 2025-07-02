#include <algorithm>
#include <climits>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
  void getPermutations(vector<int> &nums, int curN,
                       vector<vector<int>> &result) {
    if (curN == nums.size() - 1) {
      result.push_back(nums);
      return;
    }
    for (int n = curN; n < nums.size(); n++) {
      swap(nums[curN], nums[n]);
      getPermutations(nums, curN + 1, result);
      swap(nums[n], nums[curN]);
    }
  }
  vector<vector<int>> permute(vector<int> &nums) {
    vector<vector<int>> result;
    getPermutations(nums, 0, result);
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
