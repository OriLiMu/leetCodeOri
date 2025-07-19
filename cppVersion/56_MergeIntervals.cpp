#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    vector<int> usedPos(intervals.size(), 0);
    sort(intervals.begin(), intervals.end(),
         [](vector<int> &a, vector<int> &b) { return a[0] < b[0]; });
    vector<vector<int>> r = {intervals[0]};
    for (auto v : intervals) {
      auto &last = r.back();
      if (last[1] <= v[1] && last[1] >= v[0]) {
        last[1] = v[1];
      } else if (last[1] < v[1]) {
        r.push_back(v);
      }
    }
    return r;
  }
};
int main() {
  Solution s;
  // vector<vector<int>> v = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
  // vector<vector<int>> v = {{1, 4}, {4, 5}};
  // vector<vector<int>> v = {{1, 4}, {0, 2}, {3, 5}};
  vector<vector<int>> v = {{5, 5}, {1, 3}, {3, 5}, {4, 6}, {1, 1},
                           {3, 3}, {5, 6}, {3, 3}, {2, 4}, {0, 0}};
  vector<vector<int>> r = s.merge(v);
  for (auto v : r) {
    cout << v[0] << ", " << v[1] << endl;
  }
}
