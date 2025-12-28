#include <algorithm>
#include <climits>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <iterator>
#include <queue>
#include <stack>
#include <strings.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
class Solution {
public:
  vector<int> dailyTemperatures(vector<int> &temperatures) {
    vector<int> r;
    stack<int> stk;
    // for (int i = temperatures.size() - 1; i >= 0; ++i) {
    for (int i = temperatures.size() - 1; i >= 0; --i) {
      // >= 也可以pop, 因为求的是最近的满足条件的
      while (stk.size() && temperatures[i] >= temperatures[stk.top()])
        stk.pop();
      if (stk.empty())
        r.push_back(0);
      else
        r.push_back(stk.top() - i);
      stk.push(i);
    }

    reverse(r.begin(), r.end());
    return r;
  }
};

int main() {
  Solution s;
  vector<int> v = {73, 74, 75, 71, 69, 72, 76, 73};
  v = {73, 74, 75};

  for (auto &n : s.dailyTemperatures(v)) {
    cout << n << ", ";
  }

  cout << endl;
}
