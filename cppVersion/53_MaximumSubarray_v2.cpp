#include <algorithm>
#include <climits>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <iterator>
#include <queue>
#include <strings.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    int minSum = 0;
    int maxV = nums[0];
    int curSum = 0;
    for (auto n : nums) {
      minSum = min(curSum, minSum);
      curSum += n;
      maxV = max(maxV, curSum - minSum);
    }

    return maxV;
  }
};

int main() {
  Solution s;
  vector<int> v = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  v = {1};
  v = {5, 4, -1, 7, 8};
  cout << s.maxSubArray(v) << endl;
}
