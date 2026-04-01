#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
class Solution {
public:
  vector<int> findAnagrams(string s, string p) {
    unordered_map<char, int> charCountBaseline;
    deque<char> charPosQue;
    for (auto c : p) {
      charCountBaseline[c]++;
    }
    unordered_map<char, int> charCountRuntime = charCountBaseline;
    int left = 0, right = 0;
    int tmpIdx = left;
    vector<int> result;
    bool isInMatch = false;
    while (right < s.size()) {
      while (tmpIdx <= right && right < s.size()) {
        if (charCountRuntime.count(s[tmpIdx])) {  // 当前char在目标之中
          if (charCountRuntime[s[tmpIdx]] == 0) { // 现在已经没有字符可以消除了
            if (tmpIdx + 1 < s.size() &&
                !charCountRuntime.count(
                    s[tmpIdx + 1])) { // 下一个char不在目标之中, 直接跳过去
              left = tmpIdx + 1;
              tmpIdx = left;
              right = left;
              charCountRuntime = charCountBaseline;
              charPosQue.clear();
              isInMatch = false;
            } else { // 下一个char在目标之中, 维护更新状态变量
              int shiftCnt = 0;
              isInMatch = true;
              while (true) { // 把当前char之前插入的char全删掉,
                             // 因为目前的string已经从当前位置开始错了
                char frontChar = charPosQue.front();
                charCountRuntime[frontChar]++;
                shiftCnt++;
                charPosQue.pop_front();
                if (frontChar == s[tmpIdx]) {
                  left += shiftCnt;
                  if (right < left)
                    right = left;
                  tmpIdx = right + 1;
                  break;
                }
              }
            }
          } else { // 现在可以正常消除字符
            charCountRuntime[s[tmpIdx]]--;
            charPosQue.push_back(s[tmpIdx]);
            bool isAllZero = true;
            for (auto &kv : charCountRuntime) {
              if (kv.second != 0) {
                isAllZero = false;
                break;
              }
            }
            if (isAllZero) {
              result.push_back(left);
              charCountRuntime = charCountBaseline;
              left++;
            }
            right++;
            tmpIdx++;
          }
        } else { // 不在目标之中, 直接跳
          left = right + 1;
          right = left;
          tmpIdx = left;
          if (isInMatch) {
            charCountRuntime = charCountBaseline;
          }
        }
      }
    }
    return result;
  }
};

int main() {
  Solution s;
  string ss = "cbaebabacd";
  string p = "abc";
  vector<int> r = s.findAnagrams(ss, p);
  for (auto n : r) {
    cout << n << ", ";
  }
  cout << endl;
}
