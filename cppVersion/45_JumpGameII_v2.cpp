#include <algorithm>
#include <climits>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
  int jump(vector<int> &nums) {
    if (nums.size() == 1)
      return 0;
    int curIdx = 0;
    int curMax = nums[0];
    int jump_time = 0;
    int tmp_curMax = 0;
    while (curIdx < nums.size()) {
      // cout << "1: curMax: " << curMax << "curIdx: " << curIdx << endl;
      tmp_curMax = 0;
      if (curMax >= nums.size() - 1) {
        return ++jump_time;
      }
      if (curIdx <= curMax) {
        if (curIdx + nums[curIdx] > tmp_curMax) {
          tmp_curMax =
              min(curIdx + nums[curIdx], static_cast<int>(nums.size() - 1));
        }
        curIdx++;
      }
      curMax = tmp_curMax;
      jump_time++;
      // cout << "pp" << endl;
    }

    return jump_time;
  }
};
int main() {
  Solution s;
  vector<int> nums = {2, 3, 0, 1, 4};
  cout << s.jump(nums) << endl;
  return 0;
}
