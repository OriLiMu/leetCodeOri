#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int calcRob(vector<int> &nums, int curIndex, vector<bool> &flags,
              vector<bool> &isCalced, vector<int> &results) {

    if (isCalced[curIndex]) {
      return results[curIndex];
    }

    isCalced[curIndex] = true;
    if (!isCalced[curIndex - 1]) {
      calcRob(nums, curIndex - 1, flags, isCalced, results);
    }
    if (flags[curIndex - 1]) {
      if (results[curIndex - 1] > results[curIndex - 2] + nums[curIndex]) {
        results[curIndex] =
            calcRob(nums, curIndex - 1, flags, isCalced, results);
        flags[curIndex] = false;
      } else {
        results[curIndex] =
            calcRob(nums, curIndex - 2, flags, isCalced, results) +
            nums[curIndex];
        flags[curIndex] = true;
      }
    } else {
      results[curIndex] =
          calcRob(nums, curIndex - 2, flags, isCalced, results) +
          nums[curIndex];
      flags[curIndex] = true;
    }
    return results[curIndex];
  }

  int rob(vector<int> &nums) {
    vector<bool> flags(nums.size(), false);
    vector<int> results(nums.size(), 0);
    vector<bool> isCalced(nums.size(), false);
    if (nums.size() == 1) {
      return nums[0];
    } else if (nums.size() == 2) {
      if (nums[0] > nums[1]) {
        return nums[0];
      } else {
        return nums[1];
      }
    }

    results[0] = nums[0];
    if (nums[0] > nums[1]) {
      flags[0] = true;
      results[1] = results[0];
    } else {
      flags[0] = false;
      flags[1] = true;
      results[1] = nums[1];
    }

    isCalced[0] = true;
    isCalced[1] = true;

    int t = calcRob(nums, nums.size() - 1, flags, isCalced, results);
    return t;
  }
};

int main() {
  Solution s;
  vector<int> v = {1, 2, 3, 1};
  cout << s.rob(v) << endl;
  return 0;
}
