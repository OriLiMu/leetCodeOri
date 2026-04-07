#include <climits>
#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    int minPreSum = 0, curSum = 0;
    int rst = INT_MIN;
    for (auto &n : nums) {
      curSum += n;
      rst = max(rst, curSum - minPreSum);
      minPreSum = min(curSum, minPreSum);
    }

    return rst;
  }
};

int main() {
  // 1. 输入: nums = [-2,1,-3,4,-1,2,1,-5,4]
  // 输出: 6
  // 2. 输入: nums = [1]
  // 输出: 1
  // 3. 输入: nums = [5,4,-1,7,8]
  // 输出: 23
  Solution s;
  vector<int> v = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  v = {1};
  v = {5, 4, -1, 7, 8};
  v = {1, 0, 2, -3, 7};
  cout << s.maxSubArray(v) << endl;
}
