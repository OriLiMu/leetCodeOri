#include <iostream>
#include <strings.h>
#include <vector>

using namespace std;
class Solution {
public:
  struct st {
    int cur_max;
    int last_negV;
  };

  int maxProduct(vector<int> &nums) {
    int r = nums[0];
    vector<st> v(nums.size());
    v[0] = {nums[0], 1};
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] < 0) {
        if (v[i - 1].last_negV >= 0) {
          v[i].last_negV = nums[i] * v[i - 1].cur_max;
          v[i].cur_max = max(nums[i], nums[i] * v[i - 1].cur_max);
        }
        v[i] = max(v[i - 1] * nums[i], nums[i]);
      }
    }

    return r;
  }
};

int main() {
  Solution s;
  vector<int> v = {2, 3, -2, 4};
  v = {-2, 0, -1};
  // 还是测试例不完善
  v = {2, -5, -2, -4, 3};
  cout << s.maxProduct(v) << endl;
}
