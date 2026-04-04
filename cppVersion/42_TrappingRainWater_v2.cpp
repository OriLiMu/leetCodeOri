#include <iostream>
#include <stack>
#include <vector>

using namespace std;
class Solution {
public:
  struct st {
    int startIdx;
    int len;
  };
  int trap(vector<int> &nums) {
    int lastH = nums[0], idx = 0;
    int rst = 0;
    stack<int> s;
    s.push(0);
    for (int i = 0; i < nums.size(); i++) {
      while (!s.empty() && nums[s.top()] <= nums[i]) {
        rst += (nums[s.top()] - lastH) * (i - s.top() - 1);
        lastH = nums[s.top()];
        s.pop();
      }

      // 这里不是左面的最高值减去当前值
      // 左面的最高值是没有对应高度匹配的,
      // 计算水容量应该用两个边之中比较短的哪个来计算
      if (!s.empty())
        rst += (nums[i] - lastH) * (i - s.top() - 1);

      s.push(i);
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
