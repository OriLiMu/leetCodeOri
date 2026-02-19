#include <iostream>
#include <ranges>
#include <strings.h>
#include <vector>

using namespace std;
class Solution {
public:
  int maxProduct(vector<int> &nums) {
    int neg_cnt = 0, headn = 1, tailn = 1, headp = 1, tailp = 1;
    int r = nums[0], cur_p = 1, cur_len = 0;

    if (nums.size() == 1)
      return nums[0];

    for (auto &n : nums) {
      if (n == 0) {
        if (cur_len == 0)
          continue;
        if (headn < 0)
          r = max(r, max(cur_p / (headn * headp), cur_p / (tailn * tailp)));
        r = max(r, 0);
        neg_cnt = 0, headn = 1, tailn = 1, headp = 1, tailp = 1;
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
        if (headn > 0)
          headp += n;
        else
          tailp *= n;
        cur_p *= n;
        cur_len++;
        r = max(r, cur_p);
      }
    }

    // cout << cur_p << ", " << headn << ", " << headp << ", " << tailn << ", "
    //      << tailp << endl;
    r = max(r, max(cur_p / (headn * headp), cur_p / (tailn * tailp)));

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
  cout << s.maxProduct(v) << endl;
}
