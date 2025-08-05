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
  int climbStairs(int n) {
    if (n == 1)
      return 1;
    if (n == 2)
      return 2;
    int p = 1, q = 2, r = 3;
    for (int i = 2; i < n; ++i) {
      r = p + q;
      p = q;
      q = r;
    }

    return r;
  }
};
int main() {
  Solution s;
  cout << "hello" << endl;
}
