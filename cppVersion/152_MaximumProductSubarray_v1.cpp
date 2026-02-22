#include <iostream>
#include <strings.h>
#include <vector>

using namespace std;
class Solution {
public:
  int maxProduct(vector<int> &nums) {
    int neg_cnt = 0, cur_max = nums[0], r = nums[0], cur_all = nums[0];
    int v1 = 1, v2 = 1, neg1 = 1, neg2 = 1, l1 = 0, l2 = 0;
    for (int i = 0; i < nums.size(); i++) {
      int n = nums[i];
      if (n < 0) {
        if (neg1 > 0)
          neg1 = n;
        else {
          neg2 = n;
          v2 = 1;
          l2 = 0;
        }
        if (i > 0) {
          cur_all *= n;
          cur_max = max(n, cur_max * n);
        }
        neg_cnt++;
      } else if (n == 0) {
        if (neg_cnt == 0 || neg_cnt % 2 == 0)
          r = max(cur_max, r);
        else if (neg_cnt == 1) {
          if (l1 && l2)
            r = max(max(v1, v2), r);
          else if (l1)
            r = max(v1, r);
          else if (l2)
            r = max(v2, r);
          else
            r = max(0, r);
        } else {
          if (l1 && l2)
            r = max(r, max(cur_all / (v1 * neg1), cur_all / (v2 * neg2)));
          else if (l1)
            r = max(r, cur_all / (v1 * neg1));
          else if (l2)
            r = max(r, cur_all / (v2 * neg2));
          else
            r = max(r, 0);
        }
        neg_cnt = 0, v1 = 1, v2 = 1, cur_all = 1, cur_max = 1, l1 = 0, l2 = 0;
      } else {
        if (neg1 > 0) {
          v1 *= n;
          l1++;
        } else {
          v2 *= n;
          l2++;
        }

        cur_all *= n;
        cur_max = max(n, cur_max * n);
      }

      cout << "cur_all:" << cur_all << ", cur_max: " << cur_max << ", v1:" << v1
           << ", v2:" << v2 << endl;
    }

    if (neg_cnt == 0 || neg_cnt % 2 == 0)
      r = max(cur_max, r);
    else if (neg_cnt == 1) {
      if (l1 && l2)
        r = max(max(v1, v2), r);
      else if (l1)
        r = max(v1, r);
      else if (l2)
        r = max(v2, r);
    } else {
      if (l1 && l2)
        r = max(r, max(cur_all / (v1 * neg1), cur_all / (v2 * neg2)));
      else if (l1)
        r = max(r, cur_all / (v1 * neg1));
      else if (l2)
        r = max(r, cur_all / (v2 * neg2));
    }
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
  v = {-2, 0, -1}; // 返回的答案是1, 没有记录 v1 v2的长度
  v = {0};
  cout << s.maxProduct(v) << endl;
}
