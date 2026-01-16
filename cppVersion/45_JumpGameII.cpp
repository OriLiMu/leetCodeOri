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
    for (int i = 0; i < nums.size() && i <= limit; i++) {
      nextLimit = max(i + nums[i], nextLimit);
      if (i == limit) {
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
  cout << s.jump(v);
}
