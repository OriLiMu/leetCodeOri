#include <algorithm>
#include <climits>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <iterator>
#include <queue>
#include <strings.h>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;
class Solution {
public:
  int findKthLargest(vector<int> &nums, int k) {
    int l = 0, i = l + 1;
    while (i < nums.size()) {
      if (nums[i] > nums[l]) {
        swap(nums[i], nums[l]);
        l = i;
      }
    }
  }
};
int main() {
  Solution s;
  cout << "hello" << endl;
}
