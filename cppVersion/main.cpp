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
#include <vector>

using namespace std;
class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int s = 0, e = 1;
    int r = 0;
    while (e < prices.size()) {
      if (prices[e] < prices[s])
        s = e;
      else
        r = max(r, prices[e] - prices[s]);
      e++;
    }

    return r;
  }
};
int main() {
  Solution s;
  vector<int> v = {7, 1, 5, 3, 6, 4};
  cout << s.maxProfit(v);
}
