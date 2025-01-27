#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

// 还是中文先把思路写出来比较好
class Solution {
public:
  void genParen(stack<char> stk, string curStr, vector<char> remainParenthesis,
                vector<string> &result) {
    // 如果已经没有字符剩下, 并且 stk里面空的
    if (remainParenthesis.size() == 0 && stk.empty()) {
      result.push_back(curStr);
      return;
    }
    // stk 为空
    if (stk.empty()) {
      // 添加左括号 如果剩下的字符还有'('
      if (find(remainParenthesis.begin(), remainParenthesis.end(), '(') !=
          remainParenthesis.end()) {
        // find it
        stk.push('(');
        auto it = find(remainParenthesis.begin(), remainParenthesis.end(), '(');
        if (it != remainParenthesis.end()) {
          remainParenthesis.erase(it);
        }
        curStr.push_back('(');
        genParen(stk, curStr, remainParenthesis, result);
      } else {
        // 这里说明这个字符串序列不成立. 不添加, 直接返回
        return;
      }
    } else {
      // 这里的判断是stack不为空
      // 这里注意如果是基本类型的数据 stack, vector 这种自动就是深拷贝
      stack<char> tmpStk = stk;
      string tmpCurStr = curStr;
      vector<char> tmpRemainParenthsis = remainParenthesis;
      char addChar = '(';

      // 添加左括号, 需要判断 1. remainParenthesis中还有.
      if (find(remainParenthesis.begin(), remainParenthesis.end(), addChar) !=
          remainParenthesis.end()) {
        // add to stack
        tmpStk.push(addChar);
        // remove from remainParenthesis
        auto it =
            find(remainParenthesis.begin(), remainParenthesis.end(), addChar);
        if (it != remainParenthesis.end()) {
          remainParenthesis.erase(it);
        }
        curStr.push_back(addChar);
        genParen(stk, curStr, remainParenthesis, result);
      }

      // 添加右括号
      tmpStk = stk;
      tmpCurStr = curStr;
      tmpRemainParenthsis = remainParenthesis;
      addChar = ')';

      if (find(remainParenthesis.begin(), remainParenthesis.end(), addChar) !=
          remainParenthesis.end()) {
        tmpStk.pop();
        auto it =
            find(remainParenthesis.begin(), remainParenthesis.end(), addChar);
        if (it != remainParenthesis.end()) {
          remainParenthesis.erase(it);
        }
        curStr.push_back(addChar);
        genParen(stk, curStr, remainParenthesis, result);
      }
    }
  }

  vector<string> generateParenthesis(int n) {
    stack<char> stk;
    string curStr = "";
    vector<char> remainParenthesis;
    vector<string> result;
    for (int i = 0; i < n; i++) {
      remainParenthesis.push_back('(');
      remainParenthesis.push_back(')');
    }
    genParen(stk, curStr, remainParenthesis, result);
    return result;
  }
};

int main() {
  Solution s;
  vector<string> result = s.generateParenthesis(3);
  for (int i = 0; i < result.size(); i++) {
    cout << result[i] << endl;
  }
  return 0;
}
