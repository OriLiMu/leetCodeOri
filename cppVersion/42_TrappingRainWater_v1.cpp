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
    int l = 0, r = nums.size() - 1;
    int le = nums.front(), re = nums.back();
    int rst = 0;

    // 这个顺序很重要
    while (l < r && nums[l] >= nums[le]) {
      le = l;
      l++;
    }

    while (l < r && nums[r] >= nums[re]) {
      re = r;
      r--;
    }

    cout << le << "," << re << endl;
    while (l < r) {
      if (nums[le] <= nums[re]) {
        while (l < r && nums[l] <= nums[le]) {
          cout << "l: " << l << endl;
          rst += nums[le] - nums[l];
          l++;
        }
        le = l;
      } else {
        while (l < r && nums[r] <= nums[re]) {
          rst += nums[re] - nums[r];
          r--;
        }
        re = r;
      }
    }

    return rst;
  }
};

int main() {
  Solution s;
  vector<int> v = {0, 1, 0, 2};
  // v = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  // v = {4, 2, 0, 3, 2, 5};
  // v = {0, 1, 2};
  // v = {0, 1, 2, 0, 2, 0, 1};
  // v = {0, 1, 2, 0, 2, 0, 1, 1, 1, 1};
  // v = {1, 0, 1, 2, 0, 2, 0, 1, 1, 1, 1, 0, 2};
  // v = {0};
  cout << s.trap(v) << endl;
}
