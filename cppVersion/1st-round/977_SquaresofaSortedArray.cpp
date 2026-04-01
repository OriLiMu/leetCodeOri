#include <algorithm>
#include <climits>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
class Solution {
public:
  vector<int> sortedSquares(vector<int> &nums) {
    vector<int> r(nums.size());
    int lastIndex = nums.size() - 1;
    for (int i = 0, j = nums.size() - 1; lastIndex >= 0;) {
      if (nums[i] * nums[i] > nums[j] * nums[j]) {
        r[lastIndex--] = nums[i] * nums[i];
        i++;
      } else {
        r[lastIndex--] = nums[j] * nums[j];
        j--;
      }
    }

    return r;
  }
};
int main() {
  Solution s;
  cout << "hello" << endl;
}
