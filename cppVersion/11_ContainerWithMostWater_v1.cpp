// 18ms beat 70%
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
    int left = 0, right = height.size() - 1;
    int maxArea = 0;
    while (left < right) {
      maxArea = max(maxArea, (right - left) * min(height[left], height[right]));
      if (height[left] > height[right]) {
        right--;
      } else {
        left++;
      }
    }
    return maxArea;
  }
};

int main() {
  Solution s;
  vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
  cout << s.maxArea(height) << endl;
  return 0;
}
