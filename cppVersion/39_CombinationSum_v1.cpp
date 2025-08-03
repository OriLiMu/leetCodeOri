#include <cmath>
#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
  void func(vector<int> &candidates, int start, vector<int> curSelect,
            int curSum, int target, vector<vector<int>> &result, bool isSet) {
    if (curSum == target) {
      cout << "push " << endl;
      result.push_back(curSelect);
      return;
    } else if (curSum > target) {
      return;
    }

    for (int i = start; i < candidates.size(); i++) {
      curSelect.push_back(candidates[i]);
      func(candidates, i, curSelect, curSum + candidates[i], target, result,
           isSet);
      curSelect.pop_back();
    }
    return;
  }

  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    vector<vector<int>> result;
    vector<int> curSelect;
    func(candidates, 0, curSelect, 0, target, result, false);
    return result;
  }
};
int main() {
  Solution s;
  vector<int> candidates = {2, 3, 5};
  vector<vector<int>> r = s.combinationSum(candidates, 8);

  cout << "size of result:" << r.size() << endl;
  for (auto v : r) {
    for (auto n : v) {
      cout << n << ",";
    }
    cout << endl;
  }
}
