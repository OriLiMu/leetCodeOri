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
  string minWindow(string s, string t) {
    int left = 0, right = 0;
    // 这里结果最大值的定义, 就是比整个的string长度还多一个
    int rLeft = 0, rRight = s.size() + 1;
    unordered_map<char, int> charCntBaseLine;
    unordered_map<char, int> cur;
    int unMatchedCnt = t.size();
    for (auto c : t) {
      charCntBaseLine[c]++; // 这里没有必要考虑 c是不是在 charCntBaseLine之内
    }

    while (right < s.size()) {
      if (charCntBaseLine.contains(s[right])) {
        if (cur[s[right]] < charCntBaseLine[s[right]]) {
          unMatchedCnt--;
          cur[s[right]]++;
          if (unMatchedCnt == 0) {
            while (unMatchedCnt == 0) {
              if (right - left < rRight - rLeft) {
                rLeft = left;
                rRight = right;
              }

              if (!charCntBaseLine.contains(s[left]))
                left++;
              else {
                if (cur[s[left]] > charCntBaseLine[s[left]]) {
                  cur[s[left]]--;
                  left++;
                } else if (cur[s[left]] == charCntBaseLine[s[left]]) {
                  unMatchedCnt++;
                  cur[s[left]]--;
                  left++;
                  right++;
                } else {
                  cout << "错误不可能小于" << endl;
                }
              }
            }
          } else {
            right++;
          }
        } else {
          cur[s[right]]++;
          right++;
        }
      } else { // 当前字符不是目标字符
        right++;
      }
    }

    return rRight == s.size() + 1 ? "" : s.substr(rLeft, rRight + 1);
  }
};

int main() {
  Solution s;
  // string a = "ADOBECODEBANC";
  // string t = "ABC";
  // string a = "bdab";
  // string t = "ab";

  string a = "abc";
  string t = "b";
  cout << s.minWindow(a, t) << endl;
}
