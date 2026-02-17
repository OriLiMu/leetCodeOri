#include <iostream>
#include <strings.h>
#include <vector>

using namespace std;
class Solution {
public:
  void sortColors(vector<int> &nums) {
    int l = 0, r = nums.size() - 1, cur = 0;
    for (int i = 0; i <= r; ++i) {
      if (nums[i] == 2 && i <= r)
        swap(nums[i--], nums[r--]);
      else if (nums[i] == 0 && i >= l)
        swap(nums[i--], nums[l++]);
    }
  }
};
int main() {
  Solution s;
  vector<int> v = {1, 2, 0};
  // v = {2, 0, 2, 1, 1, 0};
  s.sortColors(v);
  for (auto &n : v) {
    cout << n << endl;
  }
}
