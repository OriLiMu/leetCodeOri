#include <iostream>
#include <iterator>
#include <stack>
#include <strings.h>
#include <vector>

using namespace std;
class Solution {
public:
  int longestValidParentheses(string s) {
    stack<int> stk;
    int result = 0;
    bool isFirstRight = s[0] == ')';
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '(')
        stk.push(i);
      else {
        // 这里的坐标可能 >= 0, 你的条件写错了. 注意如果是0,
        // 就不能确定是左括号还是右括号 stk.pop();       // 这里不一定能pop
        if (!stk.empty() && stk.top() > 0)
          stk.pop();
        else if (!stk.empty() && stk.top() == 0) {
          if (isFirstRight)
            stk.push(-1 * i);
          else
            stk.pop();
        } else
          stk.push(-1 * i);
      }
    }

    int l = 0, r = s.size() - 1;

    if (stk.empty())
      return s.size();
    while (!stk.empty() && r >= 0) {
      while (!stk.empty() && r >= 0) {
        if (abs(stk.top()) == r) {
          stk.pop();
          r--;
        } else
          break;
      }

      if (r < 0)
        break;
      int t;
      if (stk.empty()) {
        t = -1;
      } else {
        t = abs(stk.top());
        stk.pop(); // 这个时候 stack可能空了, 但是实际上还有一个字符串你没处理
      }
      cout << "r: " << r << ", t:" << t << endl;
      result = max(result, r - t);
      r = t - 1;
      if (stk.empty())
        result = max(result, r + 1);
    }

    return result;
  }
};

int main() {
  Solution s;
  string str = "(()";
  str = ")()())";
  str = "";
  str = "(((((((()";
  str = "(((((((()()()()()())(())";
  // str = "()";  // 没考虑第一个0, 是左括号还是右括号
  // str = ")()())"; // 在等于0的时候需要仔细的分类处理
  // 没有考虑左边界, 你假象的情况是, 一定有一个左边界的值, 你可以处理
  // 但是实际情况是, 左边界可能不会写到这个stack里面
  str = "())";
  // 如果最长的str, 包括第一个字符, 当stack空的时候,
  // 实际上还有一个字符串你没处理
  str = "(()))())(";
  // 最终五个测试例搞定
  cout << s.longestValidParentheses(str) << endl;
}
