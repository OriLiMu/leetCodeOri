#include <algorithm>
#include <climits>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <iterator>
#include <queue>
#include <ranges>
#include <strings.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
class Solution {
public:
  void func(vector<int> &allNums, int startIdx, vector<vector<int>> &result) {
    if (startIdx == allNums.size()) {
      result.push_back(allNums);
      return;
    }

    for (int i = startIdx; i < allNums.size(); ++i) {
      swap(allNums[startIdx], allNums[i]);
      func(allNums, startIdx + 1, result);
      swap(allNums[startIdx], allNums[i]);
    }

    return;
  }

  vector<vector<int>> permute(vector<int> &nums) {
    vector<vector<int>> result;
    func(nums, 0, result);
    return result;
  }
};
int main() {
  Solution s;
  cout << "hello" << endl;
}
