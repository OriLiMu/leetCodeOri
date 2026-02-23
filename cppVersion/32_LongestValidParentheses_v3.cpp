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
      char c = s[i];
      if (c == '(') {
      }
    }
  }
};
int main() {
  Solution s;
  cout << "hello" << endl;
}
