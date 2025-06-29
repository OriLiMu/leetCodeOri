#include <climits>
#include <cmath>
#include <filesystem>
#include <iostream>
#include <vector>
using namespace std;

//
class Solution {
public:
  bool isLowercase(char c) { return c >= 'a' && c <= 'z'; }
  bool isMatch(string s, string p) {
    if (s.empty()) {
      if (p.empty()) {
        return true;
      }

      // 这里之前用2作为判断条件显然不够
      while (!p.empty() && p.back() == '*') {
        p = p.substr(0, p.size() - 2);
      }

      if (p.empty()) {
        return true;
      }

      return false;
    }

    if (p.empty() && !s.empty()) {
      return false;
    }

    char lastCharS = s.back();
    char lastCharP = p.back();
    if (lastCharP == '.') {
      return isMatch(s.substr(0, s.size() - 1), p.substr(0, p.size() - 1));
    } else if (isLowercase(lastCharP)) { // one char
      if (lastCharP == lastCharS) {
        return isMatch(s.substr(0, s.size() - 1), p.substr(0, p.size() - 1));
      } else {
        return false;
      }
    } else if (lastCharP == '*') {
      char secondFromLast = p.at(p.size() - 2);
      if (secondFromLast == '.') {
        for (int i = 0; i <= s.size(); i++) {
          if (isMatch(s.substr(0, s.size() - i), p.substr(0, p.size() - 2)))
            return true;
        }
        return false;
      } else if (isLowercase(secondFromLast)) {
        for (int i = 0; i <= s.size(); i++) {
          string curStr = s.substr(0, s.size() - i);
          if (!curStr.empty()) {
            if (secondFromLast == curStr.back()) {
              if (isMatch(curStr, p.substr(0, p.size() - 2)))
                return true;
            } else {
              return isMatch(curStr, p.substr(0, p.size() - 2));
            }
          } else {
            return isMatch(curStr, p.substr(0, p.size() - 2));
          }
        }
        return false;
      }
    }

    cout << "unexpected" << endl;
    return false;
  }
};

int main() {
  Solution s;
  //  cout << "aa, a : " << s.isMatch("aa", "a") << endl;
  //  cout << "aa, a* : " << s.isMatch("aa", "a*") << endl;
  //  cout << "ab, .* : " << s.isMatch("ab", ".*") << endl;
  //  cout << "aab, c*a*b : " << s.isMatch("aab", "c*a*b") << endl;
  //  cout << "mississippi, mis*is*p* : " << s.isMatch("mississippi",
  //                                                   "mis*is*p*.")
  //       << endl;
  //  cout << "ab, .*c : " << s.isMatch("ab", ".*c") << endl;
  //  cout << "aaa, a*a : " << s.isMatch("aaa", "a*a") << endl;
  //  cout << "aaa, ab*a*c*a : " << s.isMatch("aaa", "ab*a*c*a") << endl;
  //  cout << "aaa, ab*a*c*a : " << s.isMatch("aaa", "ab*a*c*a") << endl;
  //  cout << "aaa, ab*a*c*a : " << s.isMatch("aaa", "ab*a*c*a") << endl;
  //  cout << "aaa, ab*a*c*a : " << s.isMatch("aaa", "ab*a*c*a") << endl;
  cout << s.isMatch("aaabaaaababcbccbaab", "c*c*.*c*a*..*c*") << endl;
  return 0;
}

