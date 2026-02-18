#include <climits>
#include <iostream>
#include <strings.h>
#include <vector>

using namespace std;
class Solution {
public:
  struct st {
    int cur_max;
    int negv; // 如果没有怎么办
  };

  int maxProduct(vector<int> &nums) {
    vector<st> v(nums.size());
    int r = nums[0];
    v[0].cur_max = nums[0];
    v[0].negv = nums[0] < 0 ? nums[0] : 1;
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] > 0) {
        v[i].cur_max = max(v[i - 1].cur_max * nums[i], nums[i]);
        if (v[i - 1].negv < 0)
          v[i].negv = v[i - 1].negv * nums[i];
      } else if (nums[i] == 0) {
        v[i].cur_max = v[i - 1].negv * nums[i];
        v[i].negv = 1;
      } else {
        if (v[i - 1].negv < 0) {
          v[i].cur_max = v[i - 1].negv * nums[i];
          // 这里假想这里一定是正的实际上可能是负的
          if (v[i - 1].cur_max > 0)
            v[i].negv = nums[i] * v[i - 1].cur_max;
          else if (v[i - 1].cur_max < 0)
            v[i].negv = nums[i];
          else
            v[i].negv = nums[i]; // 没考虑0的情况, 0 等于1
        } else {
          v[i].cur_max = max(v[i - 1].cur_max * nums[i], nums[i]);
          if (v[i - 1].cur_max == 0)
            v[i].negv = nums[i];
          else // 这里cur_max只能是正的
            v[i].negv = nums[i] * v[i - 1].cur_max;
        }
      }

      r = max(r, v[i].cur_max);
    }

    return r;
  }
};

int main() {
  Solution s;
  vector<int> v = {-3, 1, 2, 3, -2};
  v = {1, 2, 3, 0, 0, 0, -2, -3, -10};
  v = {-2};
  // v = {-2, -3, -10};
  // v = {0, -2, -3, -10};
  cout << s.maxProduct(v);
}
