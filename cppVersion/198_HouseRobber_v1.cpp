#include <iostream>
#include <strings.h>
#include <vector>

using namespace std;
class Solution {
public:
  int rob(vector<int> &nums) {
    if (nums.size() == 1)
      return nums[0];
    if (nums.size() == 2)
      return max(nums[0], nums[1]);
    vector<int> v(nums.size());
    v[0] = nums[0];
    v[1] = max(nums[0], nums[1]);
    for (int i = 2; i < v.size(); i++)
      v[i] = max(v[i - 1], v[i - 2] + nums[i]);
    return v.back();
  }
};
int main() {
  Solution s;
  vector<int> v = {1, 2, 3, 1};
  cout << s.rob(v) << endl;
}
