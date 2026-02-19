#include <iostream>
#include <strings.h>
#include <vector>

using namespace std;
class Solution {
public:
  int maxProduct(vector<int> &nums) {
    if (nums.size() == 1)
      return nums[0];
    int v1 = 1, v2 = 1, v3 = 1, cur_max = 1;
    int neg1 = 1, r = nums[0];
    for (auto &n : nums) {
      if (n < 0) {
        if (neg1 > 0) { // 只有一种情况, 就是 nums[0] 的情况
          cur_max = max(cur_max * n, n);
          neg1 = n;
          r = max(cur_max, r);
        } else {
          cur_max = neg1 * n * v1 * v2;
          r = max(cur_max, r);
          // v1 =
          // 这里的v的处理有了分歧
          // ABC三个负数. 当执行到B的时候v1有两种情况
          // 不包括B的v1, 包括B的v1
          // 如果这里出路不好, 那么每个负数的地方都会有两个处理方向
          v1 = v2, v2 = 1;
          neg1 = n;
        }
      } else if (n == 0) {
        v1 = 1, v2 = 1, v3 = 1;
        neg1 = 1;
        r = max(r, 0);
      } else {
        if (neg1 > 0) {
          v1 *= n;
          cur_max = v1;
        } else {
          v2 *= n;
          cur_max = v2;
        }
        r = max(r, cur_max);
      }

      cout << "cur_max: " << cur_max << ", v1:" << v1 << ", v3:" << v2
           << ", neg1: " << neg1 << endl;
    }

    return r;
  }
};

int main() {
  Solution s;
  // 作为测试例子, 你应该想到你应该添加0, 去作为判断
  vector<int> v = {2, 3, -2, 4};
  v = {-2};
  v = {2};
  v = {2, 2};
  v = {-2, 2};
  v = {-2, -2};
  v = {2, -5, -2, -4, 3};
  // v = {-2, -3, -2};
  // v = {-2, 1, 2, 3, -3, -2, -10};
  // v = {0, 0, 1};
  // v = {-2, -1};
  // 这种思路还是错误的, v2不能停止, 你还需要v3
  cout << s.maxProduct(v) << endl;
}
