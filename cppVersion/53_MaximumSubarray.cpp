#include <algorithm>
#include <climits>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    int maxValue = nums[0];
    int pre = 0;
    for (auto n : nums) {
      pre = max(pre + n, n);
      maxValue = max(pre, maxValue);
    }

    return maxValue;
  }
};
int main() {
  Solution s;
  vector<int> nums = {-1};
  cout << s.maxSubArray(nums) << endl;
}
