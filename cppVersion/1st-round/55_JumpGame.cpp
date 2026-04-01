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
  bool canJump(vector<int> &nums) {
    int limit = 0;
    for (int i = 0; i < nums.size() && i <= limit; i++) {
      int d = nums[i];
      limit = max(limit, i + d);
      if (limit >= nums.size() - 1)
        return true;
    }
    return false;
  }
};

int main() {
  Solution s;
  vector<int> v = {2, 3, 1, 1, 4};
  v = {3, 2, 1, 0, 4};
  cout << s.canJump(v);
}
