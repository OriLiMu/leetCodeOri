#include <algorithm>
#include <climits>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <vector>

using namespace std;

// good code from gpt
class Solution {
public:
  vector<string> generateParenthesis(int n) {
    if (n == 0)
      return {""};
    if (n == 1)
      return {"()"};

    vector<string> result;
    // 遍历分割点
    for (int i = 0; i < n; i++) {
      // 递归获取左右两部分的括号组合
      auto left = generateParenthesis(i);
      auto right = generateParenthesis(n - 1 - i);

      // 组合左右两部分
      for (const string &l : left) {
        for (const string &r : right) {
          result.push_back("(" + l + ")" + r);
        }
      }
    }
    return result;
  }
};

int main() {
  Solution s;
  cout << "hello" << endl;
}
