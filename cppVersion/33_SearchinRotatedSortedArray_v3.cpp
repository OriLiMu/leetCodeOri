#include <algorithm>
#include <climits>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <iterator>
#include <queue>
#include <strings.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
class Solution {
public:
  // code 1 error case {2, 1}
  // int search(vector<int> &nums, int target) {
  //   int l = 0, r = nums.size() - 1, p, mid = (l + r) >> 1;
  //   while (l < r) {
  //     mid = (l + r) >> 1; // 1. 这个是偏左的取值
  //     cout << l << ", " << r << ", mid:" << mid << endl;
  //     if (nums[mid] >= nums[0]) {
  //       l = mid; // 2. 加上上面偏左的取值, 这里会陷入死循环
  //       // 3.这个错误的核心在哪?
  //       // nums[mid] >= nums[0] 这个逻辑可能出现 mid == 0的情况,
  //       // 意味着这个比较逻辑没有意义, 因为 nums[0] 必然等于 nums[0]
  //       // 那么一开始为什么写成 >= 呢, 因为 nums[0] 也可能是最大值, >=
  //       似乎是对
  //       // nums[0]为最大值的一种保护
  //       // 我们分析这种逻辑是否成立:
  //       // 如果 nums[mid] >= nums[0] 意味着我需要摒弃左面, 如果nums[0]
  //       // 在这种情况之中就是被兵器的对象. 所以这个逻辑是错的
  //     } else
  //       r = mid - 1; // 这种情况是 nums[mid] < nums[0], 因为你需要找最大值,
  //                    // 那么这个mid 肯定不是, mid - 1没有问题
  //   }
  //
  //   cout << "mid: " << mid << ", value: " << nums[mid] << endl;
  //   return 0;
  // }

  // code 2 error case {1, 2, 3}
  // int search(vector<int> &nums, int target) {
  //   int l = 0, r = nums.size() - 1, p, mid = (l + r) >> 1;
  //   while (l < r) {
  //     mid = (l + r) >> 1; // 1. 这个是偏左的取值
  //     cout << l << ", " << r << ", mid:" << mid << endl;
  //     if (nums[mid] > nums[0]) {
  //       l = mid;
  //     } else
  //       r = mid - 1; // 这种情况是 nums[mid] < nums[0], 因为你需要找最大值,
  //                    // 那么这个mid 肯定不是, mid - 1没有问题
  //   }
  //
  //   cout << "mid: " << mid << ", value: " << nums[mid] << endl;
  //   return 0;
  // }

  // code 3, error case {4, 5, 1, 2, 3}, result is 4
  // int search(vector<int> &nums, int target) {
  //   int l = 0, r = nums.size() - 1, p, mid = (l + r) >> 1;
  //   while (l < r) {
  //     mid = (l + r) >> 1; // 1. 这个是偏左的取值
  //     if (nums[mid] > nums[0]) {
  //       if (mid == l)
  //         mid++;
  //       l = mid;
  //     } else
  //       r = mid - 1; // 这种情况是 nums[mid] < nums[0], 因为你需要找最大值,
  //                    // 那么这个mid 肯定不是, mid - 1没有问题
  //   }
  //
  //   cout << "Max Value: " << nums[mid] << endl;
  //   return 0;
  // }

  // code 4, 没有考虑越界的情况, 因为如果当前已经在最大值的位置上,
  // 还会往前走一步, 因为你不知道当前是不是最大, 这一步可能走错
  // 需要考虑的是 {2,1} 为什么正确,
  // {4, 5, 3}错误
  // 如果只剩下 {4, 5}, mid = 0,  nums[mid] > nums[0] 不成立, r
  // 退到-1(0 - 1)的位置, 答案给到-1, 这时候循环终止, 答案给到mid = 0
  // 这个错误的核心问题是把 mid = 0, 的情况和这个逻辑的一般状态, mid != 0 混淆
  //
  // v = {4, 5, 1, 2, 3}; 按这个逻辑这个答案应该是1, 实际却是4
  //
  // 第二个需要考虑的问题就是, mid = 0的情况是否需要单独拿出来
  // 如果mid == 0 意味着, left = 0, right = 0 or 1
  // if mid > left, max on the right side
  // else max on the left side, 这个逻辑我的代码没问题
  // int search(vector<int> &nums, int target) {
  //   int l = 0, r = nums.size() - 1, p, mid = (l + r) >> 1;
  //   while (l < r) {
  //     mid = (l + r) >> 1; // 1. 这个是偏左的取值
  //     if (nums[mid] > nums[0]) {
  //       if (mid == l) {
  //         mid = nums[l] > nums[r] ? l : r;
  //         break;
  //       }
  //       l = mid;
  //     } else
  //       r = mid - 1; // 这种情况是 nums[mid] < nums[0], 因为你需要找最大值,
  //                    // 那么这个mid 肯定不是, mid - 1没有问题
  //   }
  //
  //   cout << "Max Value: " << nums[mid] << endl;
  //   return 0;
  // }

  // code 5 error case: {4, 5, 1, 2, 3}, answer 4
  int search(vector<int> &nums, int target) {
    int l = 0, r = nums.size() - 1, p, mid = (l + r) >> 1;
    while (l < r) {
      mid = (l + r) >> 1; // 1. 这个是偏左的取值
      if (mid == 0) {
        mid = nums[l] > nums[r] ? l : r;
        break;
      }
      if (nums[mid] > nums[0]) {
        if (mid == l) {
          mid = nums[l] > nums[r] ? l : r;
          break;
        }
        l = mid;
      } else
        r = mid - 1;
    }

    cout << "Max Value: " << nums[mid] << endl;
    return 0;
  }
};

int main() {
  Solution s;

  // 测试用例：{数组, 期望的最大值}

  vector<pair<vector<int>, int>> testCases = {

      {{4, 5, 6, 7, 0, 1, 2}, 7},

      {{4, 5, 1, 2, 3}, 5},

      {{4, 5, 3}, 5},

      {{4}, 4},

      {{1, 2, 3}, 3},

      {{2, 1}, 2},

      {{3, 4, 5, 1, 2}, 5},

      {{5, 1, 2, 3, 4}, 5},

      {{1}, 1},

      {{2, 3, 4, 5, 1}, 5},

      {{1, 3}, 3}, // 未旋转

      {{3, 1}, 3}, // 旋转

  };

  bool allPassed = true;

  cout << "Running tests...\n";

  for (int i = 0; i < testCases.size(); ++i) {

    auto &[input, expected] = testCases[i];

    int yourResult = s.search(input, 0); // target unused

    int correctResult = findMaxCorrect(input);

    // 验证：你的结果是否等于正确结果？

    if (yourResult == expected && yourResult == correctResult) {

      cout << "✅ Test " << i + 1 << " passed: " << yourResult << "\n";

    } else {

      cout << "❌ Test " << i + 1 << " FAILED!\n";

      cout << "   Input: ";

      for (int x : input)
        cout << x << " ";

      cout << "\n   Your output: " << yourResult;

      cout << ", Expected: " << expected;

      cout << ", Correct: " << correctResult << "\n";

      allPassed = false;
    }
  }

  cout << "\n";

  if (allPassed) {

    cout << "🎉 All tests passed!\n";

  } else {

    cout << "💥 Some tests failed. Your code is NOT correct.\n";
  }

  return 0;
}
