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
  int jump(vector<int> &nums) {
    if (nums.size() == 1)
      return 0;
    int limit = nums[0], nextLimit = 0;
    int r = 0;
    for (int i = 1; i < nums.size() && i <= limit; i++) {
      if (limit >= nums.size() - 1) {
        r++;
        break;
      }

      // nextLimit 也许比开始的 limit 还要小.
      nextLimit = max(limit, max(i + nums[i], nextLimit));
      // 这个代码本身就有问题，要敏感一些处理这个代码。
      if (i == limit) { // 这里有可能，已经超出范围了，可以直接返回。
        limit = nextLimit;
        r++;
      }
    }

    return r;
  }
};

int main() {
  Solution s;
  vector<int> v = {2, 3, 1, 1, 4};
  v = {2, 3, 0, 1, 4};
  // v = {2, 1};
  v = {1, 2, 3};
  cout << s.jump(v);
}
