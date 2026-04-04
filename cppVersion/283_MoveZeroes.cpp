#include <iostream>
#include <strings.h>
#include <vector>

using namespace std;
class Solution {
public:
  void moveZeroes(vector<int> &nums) {
    int l = 0, r = 0;
    while (r < nums.size()) {
      while (l < nums.size() && nums[l] != 0)
        l++;
      r = l;
      while (r < nums.size() && nums[r] == 0)
        r++;
      if (r < nums.size())
        swap(nums[l], nums[r]);
    }
  }
};

int main() {
  Solution s;
  vector<int> v = {0, 1, 0, 3, 12};
  s.moveZeroes(v);
  for (const auto &elem : v) {
    cout << elem << " ";
  }
  cout << endl;
}
