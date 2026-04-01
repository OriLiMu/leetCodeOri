#include <algorithm>
#include <climits>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <iterator>
#include <queue>
#include <stack>
#include <strings.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
class Solution {
public:
  int findDuplicate(vector<int> &nums) {
    int slow = 0, fast = 0;
    do {
      slow = nums[slow];
      fast = nums[nums[fast]];
    } while (slow != fast);
    fast = 0;

    while (slow != fast) {
      slow = nums[slow];
      fast = nums[fast];
    }

    return fast;
  }
};

int main() {
  Solution s;
  vector<int> v = {1, 3, 4, 2, 2};
  cout << s.findDuplicate(v) << endl;
}
