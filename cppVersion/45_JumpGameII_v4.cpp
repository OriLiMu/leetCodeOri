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
    vector<int> v = {(int)nums.size() - 1};
    for (int i = nums.size() - 2; i >= 0; --i) {
      for (int j = 0; j < v.size(); ++j) {
        if (nums[i] + i >= v[j]) {
          while (v.size() > j + 1)
            v.pop_back();
          v.push_back(nums[i]);
          break;
        }
      }
    }

    return v.size();
  }
};
int main() {
  Solution s;
  vector<int> v = {2, 3, 0, 1, 4};
  cout << s.jump(v);
}
