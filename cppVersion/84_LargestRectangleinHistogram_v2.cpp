#include <algorithm>
#include <climits>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <iterator>
#include <pthread.h>
#include <queue>
#include <stack>
#include <strings.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
class Solution {
public:
  int largestRectangleArea(vector<int> &heights) {
    stack<int> stk;
    int i = 0;
    int maxv = 0;
    for (int i = 0; i < heights.size(); i++) {
      while (!stk.empty() && stk.top() > heights[i]) {
        int w = i - stk.top();
        maxv = max(maxv, w * heights[stk.top()]);
        stk.pop();
      }
    }
    return maxv;
  }
};

int main() {
  Solution s;

  cout << "hello" << endl;
}
