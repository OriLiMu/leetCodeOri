#include <iostream>
#include <strings.h>
#include <vector>

using namespace std;
class Solution {
public:
  int func(int sum, int idx, vector<int> &nums) {
    if (idx == nums.size() - 1 || idx == nums.size() - 2)
      return sum + nums[idx];
    int r1 = func(sum + nums[idx], idx + 2, nums);
    int r2 = -1;
    if (idx < nums.size() - 3)
      r2 = func(sum + nums[idx], idx + 3, nums);
    return max(r1, r2);
  }

  int rob(vector<int> &nums) {
    if (nums.size() == 1)
      return nums[0];
    if (nums.size() == 2)
      return max(nums[0], nums[1]);
    return max(func(0, 0, nums), func(0, 1, nums));
  }
};

int main() {
  Solution s;
  vector<int> v = {1, 2, 3, 1};
  cout << s.rob(v) << endl;
}
