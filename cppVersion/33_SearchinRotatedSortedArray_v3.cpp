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
  int search(vector<int> &nums, int target) {
    int l = 0, r = nums.size() - 1, p, mid;
    while (l < r) {
      mid = (l + r) >> 1;
      if (nums[mid] >= nums[0]) {
        if (mid == l)
          l = mid + 1;
        else
          l = mid;
      } else
        r = mid;
    }

    cout << nums[mid] << endl;
    return 0;
  }
};
int main() {
  Solution s;
  vector<int> v = {4, 5, 6, 7, 0, 1, 2};
  s.search(v, 0);
}
