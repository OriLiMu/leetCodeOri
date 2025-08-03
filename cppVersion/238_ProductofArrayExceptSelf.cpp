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
  vector<int> productExceptSelf(vector<int> &nums) {
    int n = nums.size();
    vector<int> pre(n, 1);
    vector<int> suf(n, 1);
    // 这个判断非常的影响, 因为这里你就判断一个, 不如直接写死
    for (int i = 1; i < n; i++) {
      // 这里你可以确定vector的大小那就直接init的时候就设置好
      pre[i] = pre[i - 1] * nums[i - 1];
    }
    for (int i = n - 2; i >= 0; i--) {
      suf[i] = suf[i + 1] * nums[i + 1];
    }
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
      ans[i] = pre[i] * suf[i];
    }

    return ans;
  }
};
int main() {
  Solution s;
  vector<int> nums = {1, 2, 3, 4};
  vector<int> r = s.productExceptSelf(nums);
  for (auto n : r) {
    cout << n << ", ";
  }
  cout << endl;
}
