#include <algorithm>
#include <climits>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <iterator>
#include <numeric>
#include <queue>
#include <stack>
#include <strings.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>

// ANSI 颜色码
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BOLD "\033[1m"
#define RESET "\033[0m"

using namespace std;
class Solution {
public:
  bool func(int cur, int si, int m, unordered_set<int> &s, vector<int> &nums,
            vector<int> &tmp) {
    if (find(s.begin(), s.end(), m - cur) != s.end())
      return true;
    for (int i = si; i < nums.size(); ++i) {
      if (nums[i] + cur > m)
        return false;
      else if (nums[i] + cur == m)
        return true;
      else {
        if (func(cur + nums[i], i + 1, m, s, nums, tmp))
          return true;
      }
    }

    return false;
  }

  bool canPartition(vector<int> &nums) {
    if (nums.size() == 1)
      return false;
    sort(nums.begin(), nums.end());
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2)
      return false;
    int m = sum / 2;
    unordered_set<int> s = {0};
    vector<int> v;
    for (int i = 0; i < nums.size(); ++i) {
      if (func(nums[i], i + 1, m, s, nums, v))
        return true;
      for (auto &n : v)
        s.insert(n);
      v.clear();
    }

    return false;
  }
};

struct TestCase {
  vector<int> input;
  bool expected;
};

void runTests() {
  Solution sol;
  vector<TestCase> tests = {{{1, 5, 11, 5}, true},
                            {{1, 2, 3, 5}, false},
                            {{1, 2, 3, 5, 1}, true},
                            {{1, 2, 3, 5, 1, 11}, false},
                            {{1, 1}, true},
                            {{1, 2, 2, 1}, true},
                            {{1, 3, 5, 5, 5, 5}, false},
                            {{100, 100, 99, 97}, false}};

  int passed = 0;
  int failed = 0;

  cout << BOLD << "\n========== 运行测试用例 ==========\n" << RESET << endl;

  for (size_t i = 0; i < tests.size(); ++i) {
    vector<int> nums = tests[i].input;
    bool result = sol.canPartition(nums);
    bool expected = tests[i].expected;

    cout << "测试 " << (i + 1) << ": [";
    for (size_t j = 0; j < nums.size(); ++j) {
      cout << nums[j];
      if (j < nums.size() - 1)
        cout << ", ";
    }
    cout << "]";

    if (result == expected) {
      cout << GREEN << " PASS " << RESET;
      cout << "(结果: " << (result ? "true" : "false") << ")";
      passed++;
    } else {
      cout << RED << " FAIL " << RESET;
      cout << "(期望: " << (expected ? "true" : "false");
      cout << ", 实际: " << (result ? "true" : "false") << ")";
      failed++;
    }
    cout << endl;
  }

  cout << BOLD << "\n========== 测试结果 ==========\n" << RESET;
  cout << "总计: " << tests.size() << " 个测试" << endl;
  cout << GREEN << "通过: " << passed << RESET << endl;
  if (failed > 0) {
    cout << RED << "失败: " << failed << RESET << endl;
  }
  cout << endl;
}

int main() { runTests(); }
