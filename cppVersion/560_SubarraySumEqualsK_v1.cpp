#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <unordered_map>
#include <vector>

using namespace std;
class Solution {
public:
  int subarraySum(vector<int> &nums, int k) {
    // 注意这里有一个0, 这个是需要的
    unordered_map<int, int> preSumCountUom = {{0, 1}};
    int curPreSum = nums[0];
    int result = 0;
    if (curPreSum == k)
      result++;
    for (int i = 1; i < nums.size(); i++) {
      if (preSumCountUom.count(curPreSum)) {
        preSumCountUom[curPreSum]++;
      } else {
        preSumCountUom[curPreSum] = 1;
      }

      // cout << "preSum i: " << curPreSum + nums[i] << endl;
      // cout << "target: " << curPreSum + nums[i] - k << endl;
      // for (auto n : preSumCountUom) {
      // cout << n.first << ", " << n.second << endl;
      // }
      if (preSumCountUom.count(curPreSum + nums[i] - k)) {
        // cout << "add: " << preSumCountUom[curPreSum + nums[i] - k] << endl;
        result += preSumCountUom[curPreSum + nums[i] - k];
      }
      // cout << "----" << endl;
      curPreSum += nums[i];
    }

    return result;
  }
};
int main() {
  Solution s;
  vector<int> nums = {1, 1, 1};
  // vector<int> nums = {-1, -1, 1};
  int k = 2;
  cout << s.subarraySum(nums, k) << endl;
}
