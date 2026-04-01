#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  void genCombination(const vector<int> &nums, vector<int> &current, int start,
                      vector<vector<int>> &result) {
    result.push_back(current);

    for (int i = start; i < nums.size(); i++) {
      current.push_back(nums[i]);
      genCombination(nums, current, i + 1, result);
      current.pop_back();
    }
  }

  vector<vector<int>> subsetsWithDup(vector<int> &nums) {
    vector<int> current = {};
    vector<vector<int>> result;
    genCombination(nums, current, 0, result);
    result.push_back({});
    return result;
  }
};

int main() {
  Solution s;
  vector<int> data = {};
  for (int i = 1; i <= 20; i++) {
    data.push_back(i);
  }

  auto r = s.subsetsWithDup(data);
  cout << r.size() << endl;
}
