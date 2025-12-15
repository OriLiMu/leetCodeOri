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
  int findMin(vector<int> &nums) {
    int l = 0, r = nums.size() - 1, mid;
    while (l < r) {
      mid = (l + r) / 2;
      if (nums[mid] >= nums[r])
        l = mid + 1;
      else
        r = mid;
    }

    return nums[l];
  }
};

int main() {
  Solution s;
  vector<int> v = {4, 5, 0, 1, 2, 3};

  cout << s.findMin(v) << endl;
}
