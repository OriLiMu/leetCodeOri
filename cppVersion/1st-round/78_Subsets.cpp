#include <algorithm>
#include <climits>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <iterator>
#include <queue>
#include <stdexcept>
#include <strings.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>

// 123, 1,2,3. len: 2 - 1,2 2,3
// length
// 5digit,
// 1
// 1-2
// 1-2-3
// 1-2-4
// 1-2-5
// 1-3
// 1-4
// 1-5

using namespace std;
class Solution {
public:
  void func(int leftLen, vector<int> &nums, vector<int> &cur, int startIdx,
            vector<vector<int>> &result) {
    // if (startIdx >= nums.size()) {
    if (leftLen == 0) {
      result.push_back(cur);
      // cur.pop_back();
      return;
    }

    for (int i = startIdx; i < nums.size(); ++i) {
      cur.push_back(nums[i]);
      func(leftLen - 1, nums, cur, i + 1, result);
      cur.pop_back();
    }
  }

  vector<vector<int>> subsets(vector<int> &nums) {
    vector<int> cur;
    vector<vector<int>> result = {{}};
    for (int l = 1; l <= nums.size(); ++l) {
      func(l, nums, cur, 0, result);
    }

    return result;
  }
};
int main() {
  Solution s;
  cout << "hello" << endl;
}
