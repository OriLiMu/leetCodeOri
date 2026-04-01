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

    int limit = nums[0];
    int r = 1, nextLimit = nums[0];
    for (int i = 1; i <= limit; ++i) {
      if (i == nums.size() - 1)
        return r;
      // 注意赋值顺序.
      nextLimit = max(nextLimit, i + nums[i]);
      if (i == limit) {
        r++;
        limit = nextLimit;
      }
    }

    return r;
  }
};

int main() {
  Solution s;
  vector<int> v = {2, 3, 0, 1, 4};
  v = {2, 3, 1, 1, 4};
  v = {1, 1, 1, 1}; // 这个例子很有意思
  cout << s.jump(v);
}
