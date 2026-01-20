#include <algorithm>
// #include <cerrno>
#include <climits>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <iterator>
#include <queue>
#include <strings.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int l = prices[0], v = 0;
    for (int i = 1; i < prices.size(); i++) {
      int cur = prices[i];
      v = max(v, cur - l);
      l = min(cur, l);
    }

    return v;
  }
};
int main() {
  Solution s;
  vector<int> v = {7, 1, 5, 3, 6, 4};
  v = {7, 6, 4, 3, 1};
  cout << s.maxProfit(v);
}
