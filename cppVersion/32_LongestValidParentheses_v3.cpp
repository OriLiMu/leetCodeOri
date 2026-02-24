#include <algorithm>
#include <climits>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <iterator>
#include <queue>
#include <stack>
#include <stop_token>
#include <strings.h>

using namespace std;
class Solution {
public:
  int longestValidParentheses(string s) {
    int r = 0;
    stack<int> stk;
    stk.push(-1);
    for (int i = 0; i < s.size(); i++) {
      int t = stk.top();
      char c = s[i];
      if (c == '(')
        stk.push(i);
      else {
        stk.pop();
        if (stk.empty())
          stk.push(i);
        else
          r = max(r, i - stk.top());
      }
    }
    return r;
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
  str = ")()())"; // 在等于0的时候需要仔细的分类处理
  // 没有考虑左边界, 你假象的情况是, 一定有一个左边界的值, 你可以处理
  // 但是实际情况是, 左边界可能不会写到这个stack里面
  // str = "())";
  // 如果最长的str, 包括第一个字符, 当stack空的时候,
  // 实际上还有一个字符串你没处理
  // str = "(()))())(";
  // str = "()";
  // 最终五个测试例搞定
  cout << s.longestValidParentheses(str) << endl;
}
