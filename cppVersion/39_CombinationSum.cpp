#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;
class Solution {
public:
  void func(vector<int> &cur, vector<int> &candidates,
            vector<vector<int>> &result, int start, int target) {
    if (start >= candidates.size()) {
      return;
    }
    int sum = accumulate(cur.begin(), cur.end(), 0);

    while (true) {
      if (sum > target) {
        return;
      } else if (sum == target) {
        result.push_back(cur);
        cout << "cur insert:" << endl;
        for (auto n : cur) {
          cout << n;
        }
        cout << endl;
        return;
      }
      start++;
      func(cur, candidates, result, start, target);
      start--;
      if (start + 1 < cur.size()) {
        cur.erase(cur.begin() + start + 1, cur.end());
      }
      auto it = upper_bound(cur.begin(), cur.end(), candidates[start]);
      cur.erase(it, cur.end());
      cur.push_back(candidates[start]);
      sum = accumulate(cur.begin(), cur.end(), 0);
    }
  }

  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> result;
    vector<int> cur = {};
    func(cur, candidates, result, 0, target);
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
