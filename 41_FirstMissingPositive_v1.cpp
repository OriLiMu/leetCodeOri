#include <algorithm>
#include <climits>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <vector>

using namespace std;

class Solution {

public:
  int targetNum = -1;
  void putCurIndexToRightPlace(vector<int> &nums, int curNum) {
    if (curNum > 0 && curNum <= nums.size()) {
      if (curNum == nums[curNum - 1])
        return;
      targetNum = nums[curNum - 1];
      if (targetNum <= 0 || targetNum > nums.size()) {
        targetNum = -1;
      }
      nums[curNum - 1] = curNum;
      if (targetNum != -1) {
        putCurIndexToRightPlace(nums, targetNum);
      }
    }
  }

  int firstMissingPositive(vector<int> &nums) {
    int l = nums.size();
    int result = 1;
    for (int i = 0; i < l; i++) {
      if (nums[i] > 100000 || nums[i] < -1) {
        nums[i] = -1;
        continue;
      }
      putCurIndexToRightPlace(nums, nums[i]);
    }

    for (int i = 0; i < l; i++) {
      if (result == nums[i]) {
        result++;
      }
    }

    return result;
  }
};

int main() {
  Solution s;
  // [43,20,39,-7,-8,-2,8,17,10,17,12,6,37,17,50,44,3,11,18,-4,44,37,28,50,15,50,19,0,45,5,37,35,35,21,39,35,27,-8,-1,47,19,22,1,1,47,-4,-7,-3,16,21,2,7,6]
  vector<int> nums = {43, 20, 39, -7, -8, -2, 8,  17, 10, 17, 12, 6,  37, 17,
                      50, 44, 3,  11, 18, -4, 44, 37, 28, 50, 15, 50, 19, 0,
                      45, 5,  37, 35, 35, 21, 39, 35, 27, -8, -1, 47, 19, 22,
                      1,  1,  47, -4, -7, -3, 16, 21, 2,  7,  6};
  int result = s.firstMissingPositive(nums);
  cout << "the result is :" << result << endl;
}

