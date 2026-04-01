#include <iostream>
#include <stack>
#include <strings.h>
#include <vector>

using namespace std;

// ANSI 颜色码
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BOLD "\033[1m"
#define RESET "\033[0m"
class Solution {
public:
  int longestValidParentheses(string s) {
    stack<int> stk;
    int r = 0;
    for (int i = 0; i < s.size(); ++i) {
      char c = s[i];
      if (c == '(')
        stk.push(i + 1);
      else {
        if (stk.empty() || stk.top() < 0)
          stk.push(-i - 1);
        else
          stk.pop();
      }
    }

    int last = s.size() + 1;
    while (stk.size()) {
      r = max(r, last - abs(stk.top()) - 1);
      last = abs(stk.top());
      stk.pop();
    }

    r = max(r, last - 1);
    return r;
  }
};

// 测试用例结构
struct TestCase {
  string input;
  int expected;
};

void runTests() {
  Solution sol;

  // ========== 在这里添加你的测试用例 ==========
  vector<TestCase> tests = {
      {"(()", 2},
      {")()())", 4},
      {"", 0},
      {"()()", 4},
      {"((()))", 6},
      {"(((((((()", 2},
      {"(((((((()()()()()())(())", 18},
      {"()", 2},
      {"())", 2},
      {"(()))())(", 4},
      // 添加更多测试用例...
  };
  // ===========================================

  int passed = 0;
  vector<int> failedIndices;

  for (int i = 0; i < tests.size(); i++) {
    int result = sol.longestValidParentheses(tests[i].input);
    bool ok = (result == tests[i].expected);

    if (ok) {
      cout << "Test " << i + 1 << ": ";
      cout << "\"" << tests[i].input << "\" -> ";
      cout << result << " [" << GREEN << "PASS" << RESET << "]" << endl;
      passed++;
    } else {
      cout << RED << BOLD << ">>> [FAIL] Test " << i + 1 << ": \""
           << tests[i].input << "\"" << RESET << endl;
      cout << RED << "           Expected: " << tests[i].expected
           << ", Got: " << result << RESET << endl;
      failedIndices.push_back(i);
    }
  }

  cout << "\n========== Result ==========" << endl;
  if (passed == tests.size()) {
    cout << GREEN << BOLD << "ALL PASSED: " << passed << "/" << tests.size()
         << RESET << endl;
  } else {
    cout << RED << BOLD << "FAILED: " << (tests.size() - passed) << "/"
         << tests.size() << RESET << endl;
    cout << RED << BOLD << "\n======== FAILED CASES ========" << RESET << endl;
    for (int idx : failedIndices) {
      int result = sol.longestValidParentheses(tests[idx].input);
      cout << RED << BOLD << "Test " << idx + 1 << RESET << endl;
      cout << RED << "  Input:    \"" << tests[idx].input << "\"" << endl;
      cout << RED << "  Expected: " << tests[idx].expected << endl;
      cout << RED << "  Got:      " << result << RESET << endl;
      cout << endl;
    }
  }
}

int main() { runTests(); }
