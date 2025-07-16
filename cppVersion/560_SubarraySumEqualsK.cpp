#include <algorithm>
#include <climits>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <unordered_map>
#include <vector>

using namespace std;
class Solution {
public:
  int subarraySum(vector<int> &nums, int k) {
    unordered_map<int, int> preSumCountUom = {{0, 1}};
    int preSum = 0;
    int result = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (preSumCountUom.count(preSum)) {
        preSumCountUom[preSum]++;
      } else {
        preSumCountUom[preSum] = 1;
      }

      cout << "preSum: " << preSum << endl;
      cout << "target: " << preSum - k << endl;
      for (auto n : preSumCountUom) {
        cout << n.first << ", " << n.second << endl;
      }
      if (preSumCountUom.count(preSum - k)) {
        cout << "add: " << preSumCountUom[preSum - k] << endl;
        result += preSumCountUom[preSum - k];
      }
      cout << "----" << endl;
      preSum += nums[i];
    }

    return result;
  }
};
int main() {
  Solution s;
  vector<int> nums = {-1, -1, 1};
  int k = 0;
  cout << s.subarraySum(nums, k) << endl;
}
