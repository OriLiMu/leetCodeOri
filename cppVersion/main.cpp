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
      int t = lstk.top();
      if (!lstk.empty() && nums[lstk.top()] <= nums[i]) {
        for (int k = lstk.top(); k < i; k++)
          r += nums[i] - nums[k];
        lstk.pop();
      }
      while (!lstk.empty() && nums[lstk.top()] <= nums[i]) {
        int m = lstk.top();
        lstk.pop();
        if (lstk.empty())
          break;
        r += (t - lstk.top() - 1) * (nums[i] - nums[t]) + nums[i] -
             nums[lstk.top()];
        t = lstk.top();
        lstk.pop();
      }

      lstk.push(i);
    }

    return r;
  }
};

int main() {
  Solution s;
  vector<int> v = {0, 1, 0, 2};
  cout << s.trap(v) << endl;
}
