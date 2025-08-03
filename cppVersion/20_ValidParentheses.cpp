#include <algorithm>
#include <climits>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
class Solution {
public:
  bool isValid(string s) {
    vector<char> stk;
    for (auto c : s) {
      if (c == '{' || c == '(' || c == '[')
        stk.push_back(c);
      if (stk.empty())
        return false;
      if (c == '}') {
        if (stk.back() == '{')
          stk.pop_back();
        else
          return false;
      }
      if (c == ')') {
        if (stk.back() == '(')
          stk.pop_back();
        else
          return false;
      }
      if (c == ']') {

        if (stk.back() == '[')
          stk.pop_back();
        else
          return false;
      }
    }

    return stk.empty();
  }
};
int main() {
  Solution s;
  string str = "()[]{}";
  str = "([)]";
  cout << s.isValid(str) << endl;
}
