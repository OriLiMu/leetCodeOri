#include <algorithm>
#include <climits>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
  int maxArea(vector<int> &height) {
    int left = 0;
    int right = height.size() - 1;
    int maxArea = 0;
    int tmp;
    while (left < right) {
      // cout << "left: " << left << "right:" << right << endl;
      tmp = min(height[left], height[right]) * (right - left);
      if (tmp > maxArea) {
        maxArea = tmp;
      }
      if (height[left] <= height[right]) {
        left++;
      } else {
        right--;
      }
      // cout << "end: left: " << left << "right:" << right << endl;
    }

    return maxArea;
  }
};
int main() {
  Solution s;
  // vector<int> h = {1, 8, 6, 2, 5, 4, 8, 3, 7};
  vector<int> h = {8, 7, 2, 1};
  cout << s.maxArea(h) << endl;
}
