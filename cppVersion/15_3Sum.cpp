#include <algorithm>
#include <climits>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    set<vector<int>> result;
    for (int i = 0; i < nums.size(); i++) {
      int left = 0;
      int right = nums.size() - 1;
      while (left < right && left != i && right != i) {
        int tmpV = nums[left] + nums[right] + nums[i];
        if (nums[left] + nums[right] + nums[i] == 0) {
          vector<int> v{nums[left], nums[right], nums[i]};
          sort(v.begin(), v.end());
          result.insert(v);
          left++;
          right--;
        } else if (tmpV > 0) {
          right--;
        } else {
          left++;
        }
      }
    }

    return vector<vector<int>>(result.begin(), result.end());
  }
};

int main() {
  Solution s;
  // [3,0,-2,-1,1,2]
  vector<int> nums = {3, 0, -2, -1, 1, 2};
  vector<vector<int>> result = s.threeSum(nums);
  for (auto &v : result) {
    cout << v[0] << " " << v[1] << " " << v[2] << endl;
  }
  return 0;
}
