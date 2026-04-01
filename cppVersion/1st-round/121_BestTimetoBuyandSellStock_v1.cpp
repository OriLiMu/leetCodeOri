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
  int maxProfit(vector<int> &prices) {
    int r = 0, minV = prices[0];
    for (int i = 1; i < prices.size(); ++i) {
      minV = min(prices[i], minV);
      r = max(r, prices[i] - minV);
    }

    return r;
  }
};
int main() {
  Solution s;
  cout << "hello" << endl;
}
