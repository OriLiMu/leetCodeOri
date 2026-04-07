#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;
class Solution {
public:
  string minWindow(string s, string t) {
    unordered_map<int, int> u, tu;
    int mcCnt = 0;
    for (auto c : t)
      u[c]++;
    int head = 0, tail = 0;
    string res;
    for (tail = 0; tail < s.size(); tail++) {
      char curChar = s[tail];
      tu[curChar]++;
      if (u.contains(curChar) && tu[curChar] <= u[curChar])
        mcCnt++;
      while (tu[s[head]] > u[s[head]])
        tu[s[head]]--;
      if (mcCnt == t.size()) {
        if (res.empty() || tail - head + 1 < res.size())
          res = s.substr(head, tail - head + 1);
      }
    }

    return res;
  }
};

int main() {
  // 1. 输入: s = "ADOBECODEBANC", t = "ABC"
  // 输出: "BANC"
  // 2. 输入: s = "a", t = "a"
  // 输出: "a"
  // 3. 输入: s = "a", t = "aa"
  // 输出: ""
  Solution s;

  string str = "ADOBECODEBANC", t = "ABC";
  cout << "hello" << endl;
}
