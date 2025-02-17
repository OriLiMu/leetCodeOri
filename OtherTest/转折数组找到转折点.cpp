#include <algorithm>
#include <climits>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  bool search(vector<int> &nums, int target) {
    int leftIndex = 0;
    int rightIndex = nums.size() - 1;
    int midIndex = (leftIndex + rightIndex) / 2;
    while (true) {
      if (midIndex > 0 && midIndex < nums.size() - 1 &&
          nums[midIndex - 1] > nums[midIndex] &&
          nums[midIndex + 1] > nums[midIndex]) {
        break;
      } else if (midIndex == 0 || midIndex == nums.size() - 1) {
        break;
      }

      if (nums[leftIndex] > nums[midIndex]) {
        rightIndex = midIndex;
        midIndex = (leftIndex + midIndex) / 2;
      } else {
        leftIndex = midIndex;
        midIndex = (rightIndex + midIndex) / 2;
      }
    }

    return false;
  }
};

int main() {
  Solution s;
  vector<int> vec = {
      1,
  };
  cout << s.search(vec, 0) << endl;
}

