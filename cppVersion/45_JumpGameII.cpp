#include <algorithm>
#include <climits>
#include <cmath>
#include <cstddef>
#include <cstdio>
#include <filesystem>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int jump(vector<int> &nums) {
    if (nums.size() == 1) {
      return 0;
    }

    int curPos = 0;
    int jumpTime = 0;
    while (true) {
      if (curPos + nums[curPos] >= nums.size() - 1) {
        return ++jumpTime;
      }
      int 子循环中当前循环变量下标 = curPos;
      int 本轮子循环中的最远目的地 = curPos + nums[curPos] + 1;
      int 本轮最远目的地对应的向量下标 = curPos;
      while (子循环中当前循环变量下标 <= curPos + nums[curPos]) {
        if (本轮子循环中的最远目的地 <=
            子循环中当前循环变量下标 + nums[子循环中当前循环变量下标]) {
          本轮最远目的地对应的向量下标 = 子循环中当前循环变量下标;
          本轮子循环中的最远目的地 =
              子循环中当前循环变量下标 + nums[子循环中当前循环变量下标];
        }
        子循环中当前循环变量下标++;
      }
      curPos = 本轮最远目的地对应的向量下标;
      jumpTime++;
    }

    return 0;
  }
};

int main() {
  Solution s;
  //  vector<int> nums = {2, 3, 1, 1, 4};
  // vector<int> nums = {1, 2, 3};
  // vector<int> nums = {0};
  vector<int> nums = {1, 1, 1, 1};
  // vector<int> nums = {2, 3, 1, 1, 4};
  cout << s.jump(nums) << endl;
}

