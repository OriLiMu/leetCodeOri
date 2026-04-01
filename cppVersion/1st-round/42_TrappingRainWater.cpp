#include <algorithm>
#include <cerrno>
#include <climits>
#include <cmath>
#include <csignal>
#include <cstddef>
#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
  int trap(vector<int> &height) {
    int l = 0;
    int r = 1;
    int result = 0;
    vector<int> edgeVec;
    while (r < height.size()) {
      while (l + 1 < height.size()) {
        if (height[l] > height[l + 1])
          break;
        l++;
      }
      if (l == height.size() - 1)
        break;
      r = l;
      while (r + 1 < height.size()) {
        if (height[r] <= height[r + 1])
          break;
        r++;
      }

      while (r + 1 < height.size()) {
        if (height[r] > height[r + 1])
          break;
        r++;
      }

      if (edgeVec.size() == 0) {
        edgeVec.push_back(l);
      }
      if (edgeVec.size() >= 2) { // 本来这部分处理我是放到下面那个循环里面的
        int leftH = height[edgeVec[edgeVec.size() - 2]];
        int last = height[edgeVec.back()];

        while (height[r] >= last && leftH >= last) {
          edgeVec.pop_back();
          if (edgeVec.size() < 2)
            break;
          leftH = height[edgeVec[edgeVec.size() - 2]];
          last = height[edgeVec.back()];
        }
      }
      edgeVec.push_back(r);

      l = r;
    }

    // 这个修改表明了尽量在第一次修改的时候, 做更多的事情
    if (edgeVec.size() >= 2) {
      int LIdx = 0;
      int RIdx = 1;
      while (RIdx < edgeVec.size()) {
        int mh = min(height[edgeVec[LIdx]], height[edgeVec[RIdx]]);
        for (int i = edgeVec[LIdx] + 1; i < edgeVec[RIdx]; i++) {
          if (mh > height[i])
            result += mh - height[i];
        }

        LIdx++;
        RIdx++;
      }
    }

    return result;
  }
};
int main() {
  Solution s;
  // vector<int> nums = {5, 4, 1, 2};
  vector<int> nums = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  cout << s.trap(nums) << endl;
}
