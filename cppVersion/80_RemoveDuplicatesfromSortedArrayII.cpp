#include <algorithm>
#include <climits>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int removeDuplicates(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    int currentNum = nums[0];
    int currentCount = 1;
    int currentIndex = 1;
    while (currentIndex < nums.size()) {
      if (currentNum == nums[currentIndex]) {
        currentCount++;
        if (currentCount > 2) {
          nums.erase(nums.begin() +
                     currentIndex); // 这里的问题是erase太频繁了.
                                    // 这个需要删除的数字不用留直接原地抹掉就行
          currentCount--;
          continue;
        }
      } else {
        currentCount = 1;
        currentNum = nums[currentIndex];
      }
      currentIndex++;
    }

    return nums.size();
  }
};

int main() {
  Solution s;
  vector<int> nums = {1, 1, 1, 1};
  cout << s.removeDuplicates(nums) << endl;
}

