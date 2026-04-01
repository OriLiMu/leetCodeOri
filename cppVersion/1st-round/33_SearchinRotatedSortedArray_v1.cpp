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
    int l = 0, r = nums.size() - 1, mid;
    if (target == nums[0])
      return 0;
    while (l <= r) {
      mid = (l + r) / 2;
      if (nums[mid] == target) {
        return mid;
      } else if (nums[mid] > target) {
        if (nums[mid] >= nums[0])
          if (target > nums[0])
            r = mid - 1;
          else
            l = mid + 1;
        else
          r = mid - 1;
      } else {
        if (nums[mid] >= nums[0])
          l = mid + 1;
        else {
          if (target > nums[0])
            r = mid - 1;
          else
            l = mid + 1;
        }
      }
    }

    return -1;
  }
};

int main() {
  Solution s;
  vector<int> v = {4, 5, 6, 7, 8, 1, 2, 3};
  cout << s.search(v, 8) << endl;
}
