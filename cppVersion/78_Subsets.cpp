#include <algorithm>
#include <climits>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  void genCombination(vector<int> &nums, int start, vector<int> &current,
                      vector<vector<int>> &result) {
    result.push_back(current);
    for (int i = start; i < nums.size(); i++) {
      current.push_back(nums[i]);
      genCombination(nums, i + 1, current, result);
      current.pop_back();
    }
  };
  vector<vector<int>> subsets(vector<int> &nums) {
    vector<vector<int>> result;
    vector<int> current;
    genCombination(nums, 0, current, result);
    return result;
  }
};

int main() {
  Solution s;
  vector<int> nums = {1, 2, 3};
  s.subsets(nums);
}
