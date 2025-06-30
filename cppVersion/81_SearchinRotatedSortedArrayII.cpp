#include <algorithm>
#include <climits>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <iterator>
#include <locale>
#include <memory_resource>
#include <vector>

using namespace std;

class Solution {
public:
  int getLeft(int curIndex, int len) {
    if (curIndex > 0)
      return curIndex - 1;
    else
      return len - 1;
  }

  int getRight(int curIndex, int len) {
    if (curIndex < len - 1)
      return curIndex + 1;
    else
      return 0;
  }

  bool search(vector<int> &nums, int target) {
    // 灵活使用stl函数
    auto minElem = min_element(nums.begin(), nums.end());
    int midIndex = distance(nums.begin(), minElem);

    bool isCross = false;
    while (true) {
      if (midIndex > 0 && nums[midIndex] == nums[midIndex - 1])
        midIndex--;
      else if (midIndex == 0) {
        if (nums[0] == nums.back() && !isCross) {
          midIndex = nums.size() - 1;
          isCross = true;
        } else {
          break;
        }
      } else {
        break;
      }
    }

    // int leftR = midIndex;
    // int rightR = midIndex == 0 ? nums.size() - 1 : midIndex - 1;
    int left = 0;
    int right = nums.size() - 1;
    int offset = midIndex;
    while (left <= right) {
      int mid = (left + right) / 2;
      int midV = nums[(mid + offset) % (nums.size())];
      if (midV == target)
        return true;
      else if (midV > target) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }

    return false;
  }
};

int main() {
  Solution s;
  vector<int> vec = {1, 0, 1, 1, 1};
  cout << s.search(vec, 0) << endl;
}
