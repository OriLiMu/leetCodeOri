#include <algorithm>
#include <climits>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
class Solution {
public:
  int firstMissingPositive(vector<int> &nums) {
    int cur = 0;
    for (int i = 0; i < nums.size(); i++) {
      cur = i;
      while (cur >= 0 && cur <= nums.size() && nums[cur] > 0 &&
             nums[cur] <= nums.size() &&
             nums[nums[cur] - 1] != nums[cur]) { // 这里没有考虑相等的情况
        if (nums[cur] != cur + 1) {              // 这部分是最吃消耗的代码
          swap(nums[cur], nums[nums[cur] - 1]);
        }
      }
    }
    for (int i = 0; i < nums.size(); i++)
      if (nums[i] != i + 1)
        return i + 1;
    return nums.size() + 1;
  }
};
int main() {
  Solution s;
  vector<int> v = {3, 4, -1, 1};
  cout << s.firstMissingPositive(v) << endl;
}
