#include <iostream>
#include <stack>
#include <vector>

using namespace std;
class Solution {
public:
  int trap(vector<int> &nums) {
    if (nums.size() == 0)
      return 0;
    stack<int> lstk;
    int r = 0;
    lstk.push(0);
    for (int i = 1; i < nums.size(); i++) {
      int cur = nums[i];
      int t = lstk.top();
      if (cur <= nums[lstk.top()])
        lstk.push(i);
      else {
        while (!lstk.empty() && nums[lstk.top()] <= cur) {
          r += cur - nums[lstk.top()];
          lstk.pop();
        }
      }
    }

    return r;
  }
};

int main() {
  Solution s;
  vector<int> v = {0, 1, 0, 2};
  cout << s.trap(v) << endl;
}
