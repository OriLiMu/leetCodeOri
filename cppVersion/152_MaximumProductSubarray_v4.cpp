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
    // v1 的设置有问题, 因为你从第一个开始算的
    int neg1 = 1, v1 = nums[0] <= 0 ? 1 : nums[0];
    for (int i = 1; i < nums.size(); ++i) {
      int n = nums[i], t = cur;
      if (n > 0 && neg1 > 0)
        v1 *= n;
      else if ((n == 0 && neg1 < 0)) {
        // 最后的处理有问题
        cout << "v1: " << v1 << ", neg: " << neg1 << endl;
        cur = max(cur_abs / (neg1 * v1), cur);
        neg1 = 1, v1 = 1;
        r = max(cur, r);
      } else if (n < 0 &&
                 neg1 > 0) // 这一步会不会和下面的冲突, 会, 所以应该放到下面
        neg1 = n;

      if (i == nums.size() - 1) {
        cur = max(cur * n, n);
        // r = max(max(cur_abs * n / (neg1 * v1), cur * n), r); // 少了一个判断,
        // cur的最大值应该是 cur = max(n, cur * n);
        // 有可能最后的
        cur_abs = abs(n * cur_abs) > n ? n * cur_abs : n; // 这里的一个笔误
        r = max(max(cur_abs, cur), r);
        break;
      }

      cout << n << ", " << cur << ", cur_abs: " << cur_abs << ", " << v1 << ", "
           << neg1 << ", " << r << endl;
      cur = max(max(n, n * cur), cur_abs * n);
      cur_abs = abs(n * cur_abs) > n ? n * cur_abs : n; // 这里的一个笔误
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
  cout << s.maxProduct(v) << endl;
}
