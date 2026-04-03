#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
  struct st {
    int startIdx;
    int len;
  };
  int trap(vector<int> &nums) {
    int rst = 0;
    if (nums.size() == 0 || nums.size() == 1)
      return 0;
    int l = 0, r = nums.size() - 1;
    int le = nums[0], re = nums.back();

    while (l < r && nums[l] >= le) {
      le = nums[l];
      l++;
    }

    l--;
    le = nums[l];
    while (l < r && nums[r] >= re) {
      re = nums[r];
      r--;
    }
    r++;
    re = nums[r];

    cout << "first: " << l << ", " << r << endl;
    while (l < r) {
      if (le < re) {
        while (l < r && nums[l] <= le) {
          rst += le - nums[l];
          l++;
        }
        if (l < r)
          le = nums[l];
      } else {
        while (l < r && nums[r] <= re) {
          rst += re - nums[r];
          r--;
        }
        if (l < r)
          re = nums[r];
      }
    }

    return rst;
  }
};

int main() {
  Solution s;
  vector<int> v = {0, 1, 0, 2};
  v = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  v = {4, 2, 0, 3, 2, 5};
  v = {0, 1, 2};
  v = {0, 1, 2, 0, 2, 0, 1};
  v = {0, 1, 2, 0, 2, 0, 1, 1, 1, 1};
  v = {1, 0, 1, 2, 0, 2, 0, 1, 1, 1, 1, 0, 2};
  v = {0};
  cout << s.trap(v) << endl;
}
