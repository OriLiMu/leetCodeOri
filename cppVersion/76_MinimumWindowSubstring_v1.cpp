#include <algorithm>
#include <climits>
#include <cmath>
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <numeric>
#include <sched.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
class Solution {
public:
  string minWindow(string s, string t) {
    unordered_map<char, int> charCntMap;
    for (auto c : t) {
      charCntMap[c]++;
    }

    int maxLen = s.size() + 1;
    int unMatchCnt = t.size();
    int left = 0, right = 0;
    int rLeft = 0, rRight = s.size() + 1;
    unordered_map<char, int> cur;
    bool isSet = false;
    bool isLeftChange = false;
    while (right < s.size()) {
      // find left
      isLeftChange = false;
      while (left < s.size()) {
        if (!charCntMap.contains(s[left]))
          ++left;
        else {
          if (right < left) // 这里也是一个细节. right应该在还没有呆过的位置上
            right = left;
          break;
        }
      }
      if (left >= s.size())
        break;

      // match
      while (right < s.size() && !isLeftChange) {
        // cout << "right:" << right << endl;
        if (charCntMap.contains(s[right])) {
          if (cur[s[right]] >= charCntMap[s[right]]) {
            cur[s[right]]++; // 这里的顺序错了, 最后在right++
            right++;
            continue;
          }
          unMatchCnt--;
          cur[s[right]]++;
          if (unMatchCnt == 0) {
            while (left < s.size()) {
              // 移动left找到最小的长度
              if (!cur.contains(s[left]))
                left++;
              else if (cur[s[left]] > charCntMap[s[left]]) {
                cur[s[left]]--;
                left++;
              } else if (cur[s[left]] == charCntMap[s[left]]) {
                if (right - left < rRight - rLeft) {
                  rLeft = left;
                  rRight = right;
                  isSet = true;
                }
                cur[s[left]]--;
                left++;
                right++;
                unMatchCnt = 1;
                isLeftChange = true;
                break;
              } else if (cur[s[left]] < charCntMap[s[left]]) {
                cout << "error" << endl;
              }
            }
          } else
            right++;
        } else
          right++;
      }
    }

    return isSet ? s.substr(rLeft, rRight - rLeft + 1) : "";
  }
};

int main() {
  Solution s;
  string a = "ADOBECODEBANC";
  string t = "ABC";
  // string a = "bdab";
  // string t = "ab";
  cout << s.minWindow(a, t) << endl;
}
