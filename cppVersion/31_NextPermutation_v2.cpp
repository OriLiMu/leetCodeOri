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
    bool isSwapped = false;
    for (int i = nums.size() - 2; i >= 0; i--) {
      sort(nums.begin() + i + 1, nums.end());
      auto upper = upper_bound(nums.begin() + i + 1, nums.end(), nums[i]);
      if (upper != nums.end()) {
        swap(*upper, nums[i]);
        isSwapped = true;
        break;
      }
    }
    if (!isSwapped) {
      sort(nums.begin(), nums.end());
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
