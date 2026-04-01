#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
class Solution {
public:
  void func(vector<int> &candidates, unordered_map<int, int> &count, int start,
            int target, int curSum, vector<int> curSelect,
            vector<vector<int>> &result) {
    // 输出当前参数信息
    // cout << ", start: " << start;
    // cout << ", curSum: " << curSum << "/" << target;
    // cout << ", 当前选择: [";
    // for (int i = 0; i < curSelect.size(); ++i) {
    // cout << curSelect[i];
    // if (i < curSelect.size() - 1)
    // cout << ", ";
    // }
    // cout << "]";
    // cout << "\n----------------------\n";
    if (curSum > target) {
      return;
    } else if (curSum == target) {
      // cout << "push back" << endl;
      result.push_back(curSelect);
      return;
    }

    for (int i = start; i < candidates.size(); i++) {
      int cnt = 0;
      for (int j = 0; j < count[candidates[i]]; j++) {
        // 这个地方的剪枝非常重要 直接从 78ms到0ms, 这个实际上是省了一次
        // push_back的操作
        if (curSum + candidates[i] > target) {
          return;
        }
        curSelect.push_back(candidates[i]);
        func(candidates, count, i + 1, target, curSum + candidates[i] * (j + 1),
             curSelect, result);
        cnt++;
      }
      for (int j = 0; j < count[candidates[i]]; j++) {
        curSelect.pop_back();
      }
    }
    return;
  }

  vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
    vector<vector<int>> result;
    vector<int> curSelect;

    unordered_map<int, int> count;
    for (auto n : candidates) {
      count[n]++;
    }
    vector<int> candidates2;
    for (const auto &pair : count) {
      candidates2.push_back(pair.first);
    }
    sort(candidates2.begin(), candidates2.end());
    func(candidates2, count, 0, target, 0, curSelect, result);
    return result;
  }
};
int main() {
  Solution s;
  vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};

  int target = 8;
  vector<vector<int>> r = s.combinationSum2(candidates, target);
  cout << "result: " << endl;
  for (auto v : r) {
    for (auto n : v) {
      cout << n << ", ";
    }
    cout << endl;
  }
}
