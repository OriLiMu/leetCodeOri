#include <algorithm>
#include <climits>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <set>
#include <system_error>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums, int target, int passedIndex) {
    sort(nums.begin(), nums.end());
    set<vector<int>> result;
    for (int i = 0; i < nums.size(); i++) {
      int left = 0;
      int right = nums.size() - 1;
      if (i == passedIndex)
        continue;

      if (left == passedIndex || left == i) {
        if (++left >= nums.size())
          break;
      }

      if (right == passedIndex || right == i) {
        if (--right < 0)
          break;
      }

      while (left < right && left != i && left != passedIndex && right != i &&
             right != passedIndex) {
        long long tmpV = 0LL + nums[left] + nums[right] + nums[i];
        if (tmpV == target) {
          vector<int> v{nums[left], nums[right], nums[i]};
          sort(v.begin(), v.end());
          result.insert(v);
          left++;
          right--;
        } else if (tmpV > target) {
          right--;
        } else {
          left++;
        }
        if (right == i || right == passedIndex) {
          if (--right < 0)
            break;
        }
        if (left == i || left == passedIndex) {
          if (++left >= nums.size())
            break;
        }
      }
    }

    return vector<vector<int>>(result.begin(), result.end());
  }

  set<vector<int>> result;
  vector<vector<int>> fourSum(vector<int> &nums, int target) {
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++) {
      vector<vector<int>> r = threeSum(nums, target - nums[i], i);
      for (vector<int> v : r) {
        v.push_back(nums[i]);
        sort(v.begin(), v.end());
        result.insert(v);
      }
    }

    return vector<vector<int>>{result.begin(), result.end()};
  }
};

int main() {
  Solution s;
  vector<int> v = {-1, 0, 1, 2, -1, -4};
  vector<vector<int>> r = s.fourSum(v, -1);
  for (vector<int> v : r) {
    for (int i : v) {
      cout << i << " ";
    }
    cout << endl;
  }
}
