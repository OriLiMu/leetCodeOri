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
    if (prices.size() == 1)
      return maxP;
    vector<int> stk = {prices[0]};
    // 这个代码默认第一个就是最小的就是一个问题
    // 丢掉了stk.size == 1 但是下一个数字比第一个数字小的情况
    for (auto n : prices) {
      if (stk.size() == 1) {
        if (n > stk.front()) {
          stk.push_back(n);
          maxP = max(maxP, n - stk.front());
        } else {
          stk.front() = n;
        }
      } else {
        if (n > stk.back()) {
          maxP = max(maxP, n - stk.front());
          stk.back() = n;
        }
        if (n < stk.front()) {
          stk.clear();
          stk.push_back(n);
        }
      }
    }
    return maxP;
  }
};
int main() {
  Solution s;
  vector<int> v = {7, 6, 4, 3, 1};
  v = {7, 1, 5, 3, 6, 4};
  cout << s.maxProfit(v) << endl;
}
