#include <algorithm>
#include <climits>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  void nextPermutation(vector<int> &nums) {
    next_permutation(nums.begin(), nums.end());
  }
};

int main() {
  Solution s;
  vector<int> nums = {3, 1, 2};
  s.nextPermutation(nums);
  for (int n : nums) {
    cout << n << ", ";
  }
}
