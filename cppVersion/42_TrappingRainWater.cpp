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
      while (!lstk.empty() && nums[lstk.top()] <= nums[i]) {
        for (int k = lstk.top(); k < i; k++)
          r += nums[i] - nums[k];
        lstk.pop();
      }
      lstk.push(nums[i]);
    }
  }
};
int main() {
  Solution s;
  cout << "hello" << endl;
}
