#include <iostream>
#include <strings.h>
#include <vector>

using namespace std;
// 这个代码有问题 在于, dfs是深度处理
// 而这个题目的特性在于, 如果在某个位置你如果被筛选出去, 后面就没有参加的意义
class Solution {
public:
  int r = 0;
  vector<int> v;
  void dfs(int sum, int pos, vector<int> &nums) {
    if (pos >= nums.size())
      return;
    if (pos == nums.size() - 1 || pos == nums.size() - 2) {
      r = max(r, sum + nums[pos]);
      return;
    } else if (pos >= nums.size()) // 你还是误以为一定需要最后一个点,
                                   // 所以把倒数第二个点排除了
      return;

    sum += nums[pos];

    dfs(sum, pos + 2, nums);
    dfs(sum, pos + 3, nums);
    return;
  }

  int rob(vector<int> &nums) {
    if (nums.size() == 1)
      return nums[0];
    dfs(0, 0, nums);
    dfs(0, 1, nums);
    return r;
  }
};

int main() {
  Solution s;
  vector<int> v = {1, 2, 3, 1};
  // v = {2, 7, 9, 3, 1};
  // v = {1, 2, 3};
  cout << s.rob(v);
}
