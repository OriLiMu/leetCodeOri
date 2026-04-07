#include <iostream>
#include <iterator>
#include <string>
#include <unordered_map>

using namespace std;
class Solution {
public:
  string minWindow(string s, string t) {
    unordered_map<int, int> u, tu;
    int mcCnt = 0;
    int head = 0, tail = 0;
    string res;
    for (auto c : t)
      u[c]++;
    for (tail = 0; tail < s.size(); tail++) {
      char cc = s[tail];
      tu[cc]++;
      if (tu[cc] <= u[cc]) // 这个不论是不是目标的char都可以这样做
        mcCnt++;
      // while (head <= tail) // 这个条件似乎也不是必须的因为, head 肯定小于tail
      //   if (tu[s[head]] > u[s[head]])
      //     tu[s[head++]]--;

      while (tu[s[head]] > u[s[head]])
        tu[s[head++]]--;

      if (mcCnt == t.size()) {
        if (res.empty() || res.size() > tail - head + 1)
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
  Solution a;
  string s = "ADOBECODEBANC", t = "ABC";
  cout << a.minWindow(s, t) << endl;
}
