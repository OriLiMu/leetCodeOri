#include <iostream>
#include <strings.h>
#include <vector>

using namespace std;
class Solution {
public:
  int maxArea(vector<int> &nums) {
    int l = 0, r = nums.size() - 1;
    int m = 0;
    while (l < r) {
      m = max(min(nums[l], nums[r]) * (r - l), m);
      if (nums[l] <= nums[r]) {
        int t = nums[l];
        while (l < nums.size() && nums[l] <= t)
          l++;
      } else {
        int t = nums[r];
        while (0 <= r && t >= nums[r])
          r--;
      }
    }

    return m;
  }
};
int main() {
  Solution s;
  vector<int> v = {1, 8, 6, 2, 5, 4, 8, 3, 7};
  v = {1, 2, 4, 4};
  cout << s.maxArea(v) << endl;
}
