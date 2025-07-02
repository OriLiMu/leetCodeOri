#include <algorithm>
#include <cinttypes>
#include <climits>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  void nextPermutation(vector<int> &nums) {
    for (int i = nums.size() - 2; i >= 0; i--) {
      int changedIndex = -1;
      bool isChanged = false;
      for (int j = i + 1; j < nums.size(); j++) {
        if (nums[j] > nums[i]) {
          if (!isChanged) {
            changedIndex = j;
            isChanged = true;
          } else {
            if (nums[changedIndex] > nums[j]) {
              changedIndex = j;
            }
          }
        }
      }

      if (isChanged) {
        int tmp = nums[changedIndex];
        nums[changedIndex] = nums[i];
        nums[i] = tmp;
        sort(nums.begin() + i + 1, nums.end());
        return;
      } else if (i == 0 && !isChanged) {
        sort(nums.begin(), nums.end());
        return;
      }
    }
  }
};

int main() {
  Solution s;
  vector<int> v = {1, 2, 3};
  s.nextPermutation(v);
  for (int n : v) {
    cout << n << ", ";
  }
}

