#include <algorithm>
#include <iostream>
// TODO: 优化 - 删除未使用的头文件
#include <ranges>      // 未使用
#include <strings.h>   // 未使用
#include <vector>

using namespace std;
class Solution {
public:
  void nextPermutation(vector<int> &nums) {
    // TODO: 优化 - 此检查可删除，算法本身能正确处理 size==1 的情况
    if (nums.size() == 1)
      return;
    int tm = nums.back();
    int i, k;
    // 步骤1: 从后向前找到第一个 nums[i] < nums[i+1] 的位置
    // 此循环保证 nums[i+1..end] 是降序排列
    for (i = nums.size() - 2; i >= 0; i--) {
      if (nums[i] >= tm)
        tm = nums[i];
      else
        break;
    }

    if (i == -1)
      // 整个数组是降序，反转得到最小排列
      reverse(nums.begin(), nums.end());
    else {
      // TODO: 优化 - 由于 nums[i+1..end] 已是降序，用 reverse 替代 sort
      // sort: O(n log n) -> reverse: O(n)
      // 优化后: reverse(nums.begin() + i + 1, nums.end());
      sort(nums.begin() + i + 1, nums.end());
      // 步骤2: 找到第一个大于 nums[i] 的元素
      for (k = i + 1; k < nums.size(); k++) {
        if (nums[i] < nums[k])
          break;
      }
      // 步骤3: 交换
      swap(nums[i], nums[k]);
    }
  }
};

int main() {
  Solution s;
  vector<int> v = {1, 2, 3};
  // v = {3, 2, 1};
  // v = {2, 3, 1};
  // v = {1, 1, 5};
  v = {1, 5, 1};
  s.nextPermutation(v);
  for (const auto &elem : v) {
    cout << elem << " ";
  }
  cout << endl;
}
