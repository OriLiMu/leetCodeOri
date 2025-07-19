#include <algorithm>
#include <climits>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
class Solution {
public:
  void rotate(vector<int> &nums, int k) {
    int mod = nums.size() % k + 1;
    int rotateCnt = nums.size() / k;
    int tmp, curIndex, idx1, idx2;
    for (int i = 0; i < k; i++) {
      curIndex = i;
      for (int j = 0; j <= rotateCnt; j++) {
        if (i + 1 >= mod && j == rotateCnt)
          continue;
        idx1 = curIndex >= nums.size()
                   ? curIndex - nums.size()
                   : curIndex; // 你这里的减法运算是有问题的, 应该是取余数,
                               // 因为这里的k可能非常大, size可能非常小.
                               // 一下子差了好几倍
        idx2 = curIndex + k >= nums.size() ? curIndex + k - nums.size()
                                           : curIndex + k;
        cout << "1:" << idx1 << ", 2:" << idx2 << endl;
        if (j == 0) {
          tmp = nums[idx2];
          nums[idx2] = nums[idx1];
        } else {
          swap(tmp, nums[idx2]);
        }
        curIndex += k;
      }
    }
  }
};
int main() {
  Solution s;
  vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
  int k = 3;
  s.rotate(nums, k);
  for (auto n : nums) {
    cout << n << ", ";
  }
}
