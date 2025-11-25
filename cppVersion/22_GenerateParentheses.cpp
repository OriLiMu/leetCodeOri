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
  void func(int leftCnt, int rightCnt, string &cur, vector<char> &stack,
            vector<string> &result) {
    if (leftCnt == 0 && rightCnt == 0) {
      result.push_back(cur);
    }

    // 回复状态
    if (leftCnt) {
      cur.push_back('(');
      stack.push_back('(');
      func(leftCnt - 1, rightCnt, cur, stack, result);
      stack.pop_back();
      cur.pop_back();
    }

    if (!stack.empty()) {
      cur.push_back(')');
      stack.pop_back();
      func(leftCnt, rightCnt - 1, cur, stack, result);
      cur.pop_back();
      stack.push_back('(');
    }

    return;
  }

  vector<string> generateParenthesis(int n) {
    string cur;
    vector<char> stack;
    vector<string> result;

    func(n, n, cur, stack, result);

    return result;
  }
};

int main() {
  Solution s;
  int n = 3;
  vector<string> r = s.generateParenthesis(n);
  for (const auto &elem : r) {
    cout << elem << " ";
  }
  cout << endl;
}
