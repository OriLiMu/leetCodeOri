#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;
class Solution {
public:
  string minWindow(string s, string t) {
    unordered_map<char, int> hs, ht;
    for (auto c : t)
      ht[c]++;

    string res;
    int cnt = 0;
    for (int i = 0, j = 0; i < s.size(); i++) {
      hs[s[i]]++;
      if (hs[s[i]] <= ht[s[i]])
        cnt++;

      while (hs[s[j]] > ht[s[j]])
        hs[s[j++]]--;
      if (cnt == t.size()) {
        if (res.empty() || i - j + 1 < res.size())
          res = s.substr(j, i - j + 1);
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
  cout << s.minWindow(str, t) << endl;
}
