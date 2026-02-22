#include <iostream>
#include <strings.h>
#include <vector>

using namespace std;
class Solution {
public:
  int maxProduct(vector<int> &nums) {
    int neg_cnt = 0, cur_max = nums[0], r = nums[0], cur_all = 1;
    int v1 = 1, v2 = 1, neg1 = 1, neg2 = 1;
    for (int i = 1; i < nums.size(); i++) {
      int n = nums[i];
      if (n < 0) {
        if (neg1 > 0)
          neg1 = n;
        else {
          neg2 = n;
          v2 = 1;
        }
        cur_all *= n;
        cur_max = max(n, cur_max * n);
        neg_cnt++;
      } else if (n == 0) {
        if (neg_cnt == 0 || neg_cnt % 2 == 0)
          r = max(cur_max, r);
        else if (neg_cnt == 1)
          r = max(max(v1, v2), r);
        else
          r = max(r, max(cur_all / (v1 * neg1), cur_all / (v2 * neg2)));
        neg_cnt = 0, v1 = 1, v2 = 1, cur_all = 1, cur_max = 1;
      } else {
        if (neg1 > 0)
          v1 *= n;
        else
          v2 *= n;

        cur_all *= n;
        cur_max = max(n, cur_max * n);
      }

      cout << "cur_all:" << cur_all << ", cur_max: " << cur_max << ", v1:" << v1
           << ", v2:" << v2 << endl;
    }

    if (neg_cnt == 0 || neg_cnt % 2 == 0)
      r = max(cur_max, r);
    else if (neg_cnt == 1)
      r = max(max(v1, v2), r);
    else
      r = max(r, max(cur_all / (v1 * neg1), cur_all / (v2 * neg2)));
    return r;
  }
};
int main() {
  Solution s;
  vector<int> v = {2, 3, -2, 4};
  cout << s.maxProduct(v) << endl;
}
