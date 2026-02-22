#include <cstdlib>
#include <iostream>
#include <strings.h>
#include <variant>
#include <vector>

using namespace std;
class Solution {
public:
  int maxProduct(vector<int> &nums) {
    int r = nums[0], cur = nums[0], cur_abs = nums[0];
    // v1 的设置有问题, 因为你从第一个开始算的, neg1 也有问题
    // int neg1 = 1, v1 = nums[0] <= 0 ? 1 : nums[0];
    int neg1 = nums[0] < 0 ? nums[0] : 1, v1 = nums[0] <= 0 ? 1 : nums[0];
    int l1 = 0;
    for (int i = 1; i < nums.size(); ++i) {
      int n = nums[i], t = cur;
      if (n > 0 && neg1 > 0) {
        v1 *= n;
      } else if ((n == 0 && neg1 < 0)) {
        // 最后的处理有问题
        cout << "v1: " << v1 << ", neg: " << neg1 << endl;
        // 这里注意一个问题. 如果cur_abs没有v1, v2部分, 那么这个部分不存在正值.
        // 所以0就是最大值. 所以, 你还要统计v1的长度
        // 我日了
        // {-1,-2,-3,0} 这样这么写就是错的. l1等于0 也可能除, 需要多个负数
        if (l1 > 1)
          cur = max(cur_abs / (neg1 * v1), cur);
        else
          cur = max(cur_abs, cur);
        neg1 = 1, v1 = 1, l1 = 0;
        r = max(cur, r);
      } else if (n < 0 &&
                 neg1 > 0) // 这一步会不会和下面的冲突, 会, 所以应该放到下面
        neg1 = n;

      if (n == 0)
        l1 = 0;
      else
        l1++;

      if (i == nums.size() - 1) {
        cur = max(cur * n, n);
        // 注意这个时候 cur_abs还没有包括最后一个数字, 所以不是这样做的
        // cur_abs = max(max(cur_abs / (neg1 * v1), cur_abs), cur_abs * n);
        cur_abs = max(max(cur_abs * n / (neg1 * v1), cur_abs), cur_abs * n);
        r = max(max(cur_abs, cur), r);
        break;
      }

      cout << n << ", " << cur << ", cur_abs: " << cur_abs << ", " << v1 << ", "
           << neg1 << ", " << r << endl;
      cur = max(max(n, n * cur), cur_abs * n);
      // 这里应该是 abs(n)
      cur_abs = abs(n * cur_abs) > abs(n) ? n * cur_abs : n; // 这里的一个笔误
      r = max(cur, r);
    }

    return r;
  }
};

int main() {
  Solution s;
  vector<int> v = {2, 3, -2, 4};
  // v = {-2, 0, -1};
  // v = {-2, 0, 1};
  // v = {1, 2, 3, 0, 0, 0, 0, 1, -1};
  // v = {1, 2, 3, 0, 0, 0, 0, 1, -1, 100};
  // v = {1, -2, 3, 0, 0, 0, 0, 1, -1, -100, -1, -2};
  // v = {1};
  // v = {1, -1, -2};
  // v = {1, -1, -2, -3, 2};
  // error case
  // v = {-4, -3};
  v = {1, 2, -1, -2, 2, 1, -2, 1, 4, -5, 4};
  v = {1, -2, 3, -4, -3, -4, -3};
  v = {1, -2, 3, -4, -3, -4, -3};
  v = {0, 2};
  v = {-2, 3, -4};
  v = {1, -2, 3, -4, -3, -4, -3};
  v = {-2, -1, -2};
  v = {-2, 0, -1};
  // 没考虑l1 如果用来统计正数长度, 可能出现无正数但是两个负数相抵的情况
  v = {-1, -2, -3, 0};
  v = {0, -2, -3}; // abs(n), 没加abs
  v = {0, -2, 0};  // 没考虑 l1 > 1的问题, 不是l1 > 0
  cout << s.maxProduct(v) << endl;
}
