#include <climits>
#include <cmath>
#include <execution>
#include <filesystem>
#include <iostream>
#include <pthread.h>

using namespace std;

class Solution {
public:
  string getCurPattern(string pattern, int index) {
    if (index >= pattern.size()) {
      return "";
    }
    string curPattern = "";
    if (index == pattern.size() - 1) {
      return pattern.substr(index, 1);
    } else {
      if (pattern[index + 1] == '*') {
        curPattern = pattern.substr(index, 2);
      } else {
        curPattern.push_back(pattern[index]);
      }
    }
    return curPattern;
  }

  string simplifyPattern(string p) {
    for (int i = 0; i < p.size() - 2; i++) {
      char nextChar = p[i + 1];
      char curChar = p[i];
      if (nextChar == '*') {
        if (curChar == '.') {
          return p.substr(0, i + 2);
        } else if (i + 2 < p.size() && curChar == p[i + 2]) {
          if (i + 3 < p.size() && p[i + 3] == '*') {
            p.erase(i + 2, 2);
          } else {
            p.erase(i + 2, 1);
          }
        }
      }
    }

    return p;
  }

  bool isMatch(string s, string p) {
    bool isMatchDone = true;
    bool isAsterMatch = false;
    char curMatchChar = ' ';
    int curPatternIndex = 0;
    string curPattern = "";
    p = simplifyPattern(p);

    for (int i = 0; i < s.size(); i++) {
      // 获取下一个字符, 便于判断是否终止 aster
      char nextChar = ' ';
      if (i <= s.size() - 2) {
        nextChar = s[i + 1];
      }

      if (!isAsterMatch) {
        curPattern = getCurPattern(p, curPatternIndex);
        if (curPattern == "") {
          return false;
        }
      }

      // * 可以为0 所以这里需要注意.
      while (curPattern.size() == 2 && curPattern[1] == '*' &&
             curPattern[0] != '.' && s[i] != curPattern[0]) {
        curPatternIndex += 2;
        curPattern = getCurPattern(p, curPatternIndex);
        if (curPattern == "")
          return false;
      }

      if (!isAsterMatch && curPattern.size() == 2 && curPattern[1] == '*') {
        isAsterMatch = true;
        curPatternIndex += 2;
      } else {
        if (!isAsterMatch) {
          curPatternIndex++;
        }
      }

      curMatchChar = curPattern[0];
      if (curMatchChar != '.' && curMatchChar != s[i]) {
        return false;
      }
      cout << s[i] << ", pattern:" << curPattern << "index:" << curPatternIndex
           << endl;

      if (isAsterMatch && nextChar != ' ' && nextChar != curMatchChar &&
          curMatchChar != '.') {
        isAsterMatch = false;
      }
    }

    if (getCurPattern(p, curPatternIndex).size() > 0) {
      return false;
    }

    return true;
  }
};

int main() {
  Solution s;
  //  cout << s.simplifyPattern("a*a*") << endl;
  cout << s.isMatch("aaa", "a*a") << endl;
  return 0;
}
