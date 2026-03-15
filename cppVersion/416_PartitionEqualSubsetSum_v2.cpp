#include <iostream>
#include <numeric>
#include <strings.h>
#include <vector>

using namespace std;
class Solution {
public:
  bool canPartition(vector<int> &nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2)
      return false;
    sum /= 2;
    vector<int> v(sum + 1);
    v[0] = 1;
    for (auto &n : nums) {
      // 这里的问题, 需要是 k >= nums[i] 而不是 i
      // 这个确实是一个易错点
      for (int k = sum; k >= n; --k)
        v[k] |= v[k - n];
    }
    return v.back();
  }
};

// 测试辅助函数
void runTest(Solution &s, vector<int> nums, bool expected, int testNum) {
  bool result = s.canPartition(nums);
  cout << "Test " << testNum << ": ";
  cout << "[";
  for (int i = 0; i < nums.size(); i++) {
    cout << nums[i];
    if (i < nums.size() - 1)
      cout << ", ";
  }
  cout << "] => ";
  cout << "Expected: " << expected << ", Actual: " << result;
  cout << " [" << (result == expected ? "PASS" : "FAIL") << "]" << endl;
}

void testCanPartition() {
  Solution s;
  int testNum = 1;

  cout << "========================================" << endl;
  cout << "Testing canPartition Function" << endl;
  cout << "========================================" << endl;

  // 边界情况测试
  cout << "\n--- Boundary Cases ---" << endl;
  runTest(s, {1, 2, 5}, false, testNum++); // 空数组
  runTest(s, {}, true, testNum++);         // 空数组
  runTest(s, {1}, false, testNum++);       // 单元素
  runTest(s, {0}, false, testNum++);       // 单个0
  runTest(s, {1, 1}, true, testNum++);     // 两元素相等
  runTest(s, {1, 2}, false, testNum++);    // 两元素不等
  runTest(s, {0, 0}, true, testNum++);     // 两个0

  // 正常情况 - 可分割
  cout << "\n--- Normal Cases (Can Partition) ---" << endl;
  runTest(s, {1, 5, 11, 5}, true, testNum++);         // [1,5,5] 和 [11]
  runTest(s, {1, 2, 3, 4, 5, 6, 7}, true, testNum++); // 总和28
  runTest(s, {1, 1, 1, 1, 1, 1}, true, testNum++);    // 全1
  runTest(s, {2, 2, 2, 2}, true, testNum++);          // 全2
  runTest(s, {3, 3, 3, 3, 3}, false, testNum++);      // 5个3，总和15（奇数）
  runTest(s, {1, 2, 5}, false, testNum++);            // 总和8，但无法分割
  runTest(s, {1, 2, 3, 6}, true, testNum++);          // [1,2,3] 和 [6]

  // 正常情况 - 不可分割
  cout << "\n--- Normal Cases (Cannot Partition) ---" << endl;
  runTest(s, {1, 2, 3, 5}, false, testNum++); // 总和11（奇数）
  runTest(s, {1, 2, 5}, false, testNum++);    // 总和8，无法分割
  runTest(s, {2, 2, 3, 5}, false, testNum++); // 总和12，无法分割

  // 特殊情况
  cout << "\n--- Special Cases ---" << endl;
  runTest(s, {0, 0, 0, 0}, true, testNum++);       // 全0数组
  runTest(s, {100, 100}, true, testNum++);         // 大数相等
  runTest(s, {1, 2, 5, 10, 20}, false, testNum++); // 总和38，无法分割
  runTest(s, {1, 2, 3, 4, 5, 7}, true, testNum++); // 总和22，可以分割
  runTest(s, {9, 5, 5, 9, 8, 7}, true, testNum++); // 复杂情况

  // 大数组测试
  cout << "\n--- Large Array Cases ---" << endl;
  vector<int> large1 = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}; // 10个1
  runTest(s, large1, true, testNum++);

  vector<int> large2 = {2, 2, 2, 2, 2, 2, 2, 2, 2, 1}; // 总和19（奇数）
  runTest(s, large2, false, testNum++);

  vector<int> large3 = {10, 10, 10, 10, 10, 10}; // 6个10
  runTest(s, large3, true, testNum++);

  cout << "\n========================================" << endl;
  cout << "Test Completed" << endl;
  cout << "========================================" << endl;
}

int main() {
  testCanPartition();
  return 0;
}
