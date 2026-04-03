#include <iostream>
#include <stack>
#include <vector>

using namespace std;
class Solution {
public:
  int trap(vector<int> &nums) {
    stack<int> s;
    int lastH = 0;
    int rst = 0;
    s.push(0);
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] <= nums[s.top()])
        s.push(i);
      else {
        while (!s.empty() && nums[i] >= nums[s.top()]) {
          rst += (nums[s.top()] - lastH) * (i - s.top() - 1);
          lastH = nums[s.top()];
          s.pop();
        }
        if (!s.empty())
          rst += (i - s.top() - 1) * (nums[i] - lastH);
        s.push(i);
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
  // 0, 0, 1, 1, 1, 3, 3, 4, 4,4, 4, 4, 11}
  v = {1, 0, 1, 2, 0, 2, 0, 1, 1, 1, 1, 0, 2};
  // v = {0};
  // v = {4, 2, 3};
  cout << s.trap(v) << endl;
}
