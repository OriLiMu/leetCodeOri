#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
class Solution {
public:
  int subarraySum(vector<int> &nums, int k) {
    int curSum = 0;
    unordered_map<int, int> u;
    int rst = 0;
    u[0] = 1;
    for (auto &n : nums) {
      curSum += n;
      rst += u[curSum - k];
      // 如果相等也是需要添加的, 这个
      // 一开始我这里添加了 else
      u[curSum]++;
    }

    return rst;
  }
};

int main() {
  // 1. 输入: nums = [1,1,1], k = 2
  // 输出: 2
  // 2. 输入: nums = [1,2,3], k = 3
  // 输出: 2
  Solution s;
  vector<int> v = {1, 1, 1};
  int k = 3;
  v = {1, 2, 3, 3, 3, 3, 1, 2, 3, 0, -4, 7};
  // 没想到的例子
  // v = {1, -1, 0};
  // k = 0;
  cout << s.subarraySum(v, k) << endl;
}
