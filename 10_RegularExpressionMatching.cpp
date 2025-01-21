#include <climits>
#include <cmath>
#include <filesystem>
#include <iostream>

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

  bool isMatch(string s, string p) {
    bool isMatchDone = true;
    bool isAsterMatch = false;
    char curMatchChar = ' ';
    int curPatternIndex = 0;
    string curPattern = "";
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
             s[i] != curPattern[0]) {
        curPatternIndex += 2;
        curPattern = getCurPattern(p, curPatternIndex);
        if (curPattern == "")
          return false;
      }

      if (curPattern.size() == 2 && curPattern[1] == '*') {
        isAsterMatch = true;
        curPatternIndex += 2;
      } else {
        curPatternIndex++;
      }

      curMatchChar = curPattern[0];
      if (curMatchChar != '.' && curMatchChar != s[i]) {
        return false;
      }

      if (isAsterMatch && nextChar != ' ' && nextChar != curMatchChar) {
        isAsterMatch = false;
      }
    }

    return true;
  }
};

int main() {
  Solution s;
  cout << s.isMatch("aa", "a") << endl;
  return 0;
}
