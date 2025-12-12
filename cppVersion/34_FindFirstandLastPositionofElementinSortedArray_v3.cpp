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
  vector<int> searchRange(vector<int> &nums, int target) {
    int mid, l = 0, r = nums.size() - 1, dst = -1;
    while (l <= r) {
      mid = (l + r) / 2;
      if (nums[mid] == target) {
        dst = mid;
        break;
      } else if (nums[mid] > target) {
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
    if (dst == -1)
      return {-1, -1};
    l = dst - 1;
    r = dst + 1;
    while (l >= 0 && nums[l] == target)
      l--;
    while (r < nums.size() && nums[r] == target)
      r++;
    return {l + 1, r - 1};
  }
};

int main() {
  Solution s;
  vector<int> v = {5, 7, 7, 8, 8, 10};
  vector<int> r = s.searchRange(v, 6);
  cout << r[0] << ", " << r[1] << endl;
}
