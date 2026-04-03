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
    if (nums.size() <= 1)
      return 0;
    int l = 0, r = nums.size() - 1;
    // 值和index的理解偏差, 这个方面你的代码的命名一定要准确
    int le = 0, re = nums.size() - 1;
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

    // 有没有可能, l, r没进入处理循环他们的值本来就是对的
    // 这样来看代码的整体逻辑还是不够细致. 一些细节没有处理清楚
    // l--, r++;
    //
    // 这个逻辑更稳妥, 但是后面的代码也需要注意
    l = le, r = re;

    while (l < r) {
      if (nums[le] <= nums[re]) {
        while (l < r && nums[l] <= nums[le]) {
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
  v = {1, 0, 1, 2, 0, 2, 0, 1, 1, 1, 1, 0, 2};
  // v = {0};
  // v = {4, 2, 3};
  cout << s.trap(v) << endl;
}
