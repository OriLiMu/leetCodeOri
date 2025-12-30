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
    heights.insert(heights.begin(), 0);
    heights.push_back(0);
    for (int i = 0; i < heights.size(); i++) {
      while (!stk.empty() && heights[stk.top()] > heights[i]) {
        int h = heights[stk.top()];
        stk.pop();
        int w = i - stk.top() - 1;
        maxv = max(maxv, w * h);
      }
      stk.push(i);
    }
    return maxv;
  }
};

int main() {
  Solution s;
  vector<int> v = {2, 4, 0, 2, 0};
  v = {0};
  v = {2, 4};
  v = {2, 1, 2};
  cout << s.largestRectangleArea(v);
}
