#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;
class Solution {
public:
  string minWindow(string s, string t) {
    unordered_map<int, int> u, tu;
    for (auto &c : t)
      u[c]++;
    int head = 0, tail = 0, step_cnt = s.size();
    string rst = s; // 你这个条件是默认包含了, 但是可能一个可能值都没有
    while (tail < s.size()) {
      char c = s[tail];
      if (u.contains(c)) {
        tu[c]++;
        bool isCvr = true;
        for (auto &kv : tu) {
          if (u[kv.first] > kv.second) {
            isCvr = false;
            break;
          }
        }
        if (isCvr) {
          if (rst.size() > tail - head + 1)
            rst = s.substr(head, tail - head + 1);
          step_cnt = 0;
          while () {
          }
        }
      }
    }
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
  cout << "hello" << endl;
}
