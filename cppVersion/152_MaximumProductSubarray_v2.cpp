#include <climits>
#include <iostream>
#include <strings.h>
#include <vector>

using namespace std;
class Solution {
public:
  int maxProduct(vector<int> &nums) {
    int r = nums[0];
    int v1 = 1, v2 = 1, v3 = 1;
    int neg1 = 1, neg2 = 1;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] > 0) {
        if (neg1 > 0)
          v1 *= nums[i];
        else if (neg1 < 0 && neg2 > 0)
          v2 *= nums[i];
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
