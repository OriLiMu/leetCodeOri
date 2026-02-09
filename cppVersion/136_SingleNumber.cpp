#include <iostream>
#include <strings.h>
#include <vector>

using namespace std;
class Solution {
public:
  int singleNumber(vector<int> &nums) {
    int r = 0;
    for (auto &n : nums)
      r ^= n;

    return r;
  }
};
int main() {
  Solution s;
  vector<int> v = {2, 2, 1};
  cout << s.singleNumber(v) << endl;
}
