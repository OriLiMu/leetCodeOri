#include <algorithm>
#include <climits>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  bool isLowercase(char c) { return c >= 'a' && c <= 'z'; }
  bool isMatch(string originStr, string pattern) {
    if (originStr.empty()) {
      if (pattern.empty())
        return true;
      else {
        while (!pattern.empty() && pattern.back() == '*') {
          pattern = pattern.substr(0, pattern.size() - 2);
        }
        if (pattern.empty())
          return true;
        else
          return false;
      }
    }

    if (pattern.empty()) {
      if (!originStr.empty())
        return false;
    }

    if (originStr.back() == pattern.back() || pattern.back() == '.') {
      return isMatch(originStr.substr(0, originStr.size() - 1),
                     pattern.substr(0, pattern.size() - 1));
    } else if (pattern.back() != '*' && originStr.back() != pattern.back()) {
      return false;
    } else if (pattern.back() == '*') {
      char SecLastChar = pattern.at(pattern.size() - 2);
      if (SecLastChar == '.') {
        for (int i = 0; i <= originStr.size(); i++) {
          if (isMatch(originStr.substr(0, originStr.size() - i),
                      pattern.substr(0, pattern.size() - 2))) {
            return true;
          }
        }
      } else {
        for (int i = 0; i <= originStr.size(); i++) {
          string curString = originStr.substr(0, originStr.size() - i);
          if (isMatch(curString, pattern.substr(0, pattern.size() - 2))) {
            return true;
          }
          if (!curString.empty() && curString.back() != SecLastChar) {
            return false;
          }
        }
      }
    }

    return false;
  }
};

int main() {
  Solution s;
  // cout << "aa, a : " << s.isMatch("aa", "a") << endl;
  // cout << "aa, a* : " << s.isMatch("aa", "a*") << endl;
  // cout << "ab, .* : " << s.isMatch("ab", ".*") << endl;
  // cout << "aab, c*a*b : " << s.isMatch("aab", "c*a*b") << endl;
  // cout << "mississippi, mis*is*p* : " << s.isMatch("mississippi",
  // "mis*is*p*.")
  //      << endl;
  // cout << "ab, .*c : " << s.isMatch("ab", ".*c") << endl;
  // cout << "aaa, a*a : " << s.isMatch("aaa", "a*a") << endl;
  // cout << "aaa, ab*a*c*a : " << s.isMatch("aaa", "ab*a*c*a") << endl;
  // cout << "aaa, ab*a*c*a : " << s.isMatch("aaa", "ab*a*c*a") << endl;
  // cout << "aaa, ab*a*c*a : " << s.isMatch("aaa", "ab*a*c*a") << endl;
  // cout << "aaa, ab*a*c*a : " << s.isMatch("aaa", "ab*a*c*a") << endl;
  cout << "a, .*..a* : " << s.isMatch("a", ".*..a*") << endl;
  return 0;
}
