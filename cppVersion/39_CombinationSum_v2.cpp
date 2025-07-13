#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;
class Solution {
public:
  void func(vector<int> &candidates, vector<int> &curSelected,
            vector<vector<int>> &result, int start, int end, int size,
            int target) {

    if (start >= candidates.size())
      return;
    int sum = 0;
    if (!curSelected.empty()) {
      sum = accumulate(curSelected.begin(), curSelected.begin() + end + 1, 0);
    }

    int cnt = 0;
    while (true) {
      if (sum > target)
        return;
      else if (sum == target) {
        vector<int> subVect(curSelected.begin(), curSelected.begin() + end + 1);
        result.push_back(subVect);
        return;
      } else {
        func(candidates, curSelected, result, start + 1, end, end, target);
        if (curSelected.size() == 0) {
          curSelected.push_back(candidates[start]);
        } else {
          if (end + 1 < static_cast<int>(curSelected.size())) {
            curSelected[max(end + 1, 0)] = candidates[start];
          } else {
            curSelected.push_back(candidates[start]);
          }
        }
        end++;
      }

      if (end >= 0) {
        sum = accumulate(curSelected.begin(), curSelected.begin() + end + 1, 0);
      } else {
        sum = 0;
      }
    }
  }
  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    vector<int> curSelected;
    vector<vector<int>> result;
    func(candidates, curSelected, result, 0, -1, 0, target);
    return result;
  }
};
int main() {
  vector<int> candidates = {2, 3, 1};
  int target = 5;
  Solution s;
  vector<vector<int>> r = s.combinationSum(candidates, target);
  cout << "result: " << endl;
  for (auto v : r) {
    for (auto n : v) {
      cout << n << ", ";
    }
    cout << endl;
  }
}

// 重要问题, 这个end是最后一个没被用的还是已经被使用的
