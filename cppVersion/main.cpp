#include <climits>
#include <iostream>
#include <strings.h>
#include <vector>

using namespace std;
class Solution {
public:
  int maxProduct(vector<int> &nums) {
    int r = nums[0];
    vector<int> v(nums.size());
    v[0] = nums[0] > 0 ? nums[0] : 1;
    int curNeg = nums[0] < 0 ? nums[0] : 1;
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] < 0) {
        if (curNeg < 0) {
          v[i] = curNeg * nums[i] * v[i - 1];
          r = max(r, v[i]);
        } else
          v[i] = 1;
        curNeg = nums[i];
      } else if (nums[i] == 0) {
        v[i] = 1;
        curNeg = 1;
        r = max(r, 0);
      } else {
        v[i] = v[i - 1] * nums[i];
        r = max(r, v[i]);
      }
    }

    return r;
  }
};
int main() {
  Solution s;
  vector<int> v = {1, 2, 3};
  v = {2};
  v = {-2};
  v = {1, 2, 3, 0};
  v = {-1, -2, -4};
  cout << s.maxProduct(v);
}
