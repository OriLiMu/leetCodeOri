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
    int maxP = 0;
    for (int i = 0, minp = INT_MAX; i < prices.size(); i++) {
      minp = min(minp, prices[i]);
      maxP = max(maxP, prices[i] - minp);
    }

    return maxP;
  }
};
int main() {
  Solution s;
  cout << "hello" << endl;
}
