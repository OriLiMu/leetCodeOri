#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  void backtrack(int target, vector<int> &candidates, int start, int curSum,
                 vector<int> &cur, vector<vector<int>> &result) {
    if (curSum == target) {
      result.push_back(cur);
      return;
    }

    if (curSum > target) {
      return;
    }

    for (int i = start; i < candidates.size(); ++i) {
      // 剪枝：如果当前数字加上当前和已经超过目标，由于数组已排序，后面的数字更大
      if (curSum + candidates[i] > target) {
        break;
      }

      cur.push_back(candidates[i]);
      backtrack(target, candidates, i, curSum + candidates[i], cur, result);
      cur.pop_back();
    }
  }

  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    vector<vector<int>> result;
    vector<int> cur;

    if (candidates.empty()) {
      return result;
    }

    // 排序以便剪枝
    sort(candidates.begin(), candidates.end());
    backtrack(target, candidates, 0, 0, cur, result);
    return result;
  }
};
int main() {
  Solution s;
  vector<int> nums = {2, 3, 6, 7};
  int target = 7;
  vector<vector<int>> r = s.combinationSum(nums, target);
  for (auto &v : r) {
    for (auto &n : v) {
      cout << n << ", ";
    }
    cout << endl;
  }
}
