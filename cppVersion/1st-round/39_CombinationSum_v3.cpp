#include <algorithm>
#include <climits>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <iterator>
#include <queue>
#include <strings.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
class Solution {
public:
  // 每次调用的时候都希望恢复到调用之前的状态
  // 如何保证状态的复原, 是自己保证还是上一级保证
  void func(int target, vector<int> &candidates, int curSum, vector<int> &cur,
            int nextNumIdx, vector<vector<int>> &result) {
    if (curSum == target) {
      result.push_back(cur);
      return;
    }

    if (nextNumIdx >= candidates.size()) {
      return;
    }

    int curNumCount = 0;
    while (curSum + curNumCount * candidates[nextNumIdx] <= target) {
      if (curNumCount)
        cur.push_back(candidates[nextNumIdx]);
      func(target, candidates, curSum + curNumCount * candidates[nextNumIdx],
           cur, nextNumIdx + 1, result);
      curNumCount++;
    }

    curNumCount--;

    // cout << "cur: ";
    // for (auto &n : cur)
    //   cout << n << ", ";
    // cout << endl;
    cout << "count: " << curNumCount << endl;
    for (int i = 0; i < curNumCount; ++i)
      cur.pop_back();
  }
  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    sort(candidates.begin(), candidates.end());
    int curSum = 0;
    vector<int> cur;
    vector<vector<int>> result;

    func(target, candidates, curSum, cur, 0, result);
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
