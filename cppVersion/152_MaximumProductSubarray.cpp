#include <iostream>
#include <ranges>
#include <strings.h>
#include <vector>

using namespace std;
class Solution {
public:
  int maxProduct(vector<int> &nums) {
    int neg_cnt = 0, headn = 1, tailn = 1, headp = 1, tailp = 1;
    int r = nums[0], cur_p = 1, cur_len = 0, headl = 0, taill = 0;

    if (nums.size() == 1)
      return nums[0];

    for (auto &n : nums) {
      if (n == 0) {
        if (cur_len == 0)
          continue;
        if (headn < 0) {
          if (neg_cnt % 2 == 0)
            r = max(r, cur_p);
          else {
            if (headl > 0 && taill > 0)
              r = max(r, max(cur_p / (headn * headp), cur_p / (tailn * tailp)));
            else if (headl == 0 && taill > 0)
              r = max(r, cur_p / (tailn * tailp));
            else if (taill == 0 && headl > 0)
              r = max(r, cur_p / (headn * headp));
          }
        }
        r = max(r, 0);
        neg_cnt = 0, headn = 1, tailn = 1, headp = 1, tailp = 1, headl = 0,
        taill = 0;
        cur_p = 1;
      } else if (n < 0) {
        if (headn > 0)
          headn = n;
        tailn = n;
        neg_cnt++;
        cur_p *= n;
        cur_len++;
        r = max(r, cur_p);
        tailp = 1;
      } else {
        if (headn > 0) {
          headp *= n;
          headl++;
        } else {
          tailp *= n;
          taill++;
        }
        cur_p *= n;
        cur_len++;
        r = max(r, cur_p);
      }
    }

    cout << cur_p << ", " << headn << ", " << headp << ", " << tailn << ", "
         << tailp << endl;
    // 还需要判断 headp 和 tailp 的长度
    if (neg_cnt % 2 == 0)
      r = max(r, cur_p);
    else {
      if (headl > 0)
        r = max(r, cur_p / (headn * headp));
      if (taill > 0)
        r = max(r, cur_p / (tailn * tailp));
    }
    // 还是headn 和 tailn你写成了一个就会有问题
    // 有便利也有麻烦
    // 一般的思路还是分开处理
    // 合并之后, 逻辑容易混乱
    // 本质上你这种算法需要清楚负数的数量

    return r;
  }
};
int main() {
  Solution s;
  vector<int> v = {1, 2, 3};
  // v = {2};
  // v = {-2};
  // v = {1, 2, 3, 0};
  v = {-1, -2, -4};
  v = {-2, -3, 7};
  v = {-2, 4, -3, 1, 2, -10, 7};
  v = {2, 3, -2, 4};
  v = {-2, 0, -1};
  v = {1, 0, -1, 2, 3, -5, -2};
  cout << s.maxProduct(v) << endl;
}
