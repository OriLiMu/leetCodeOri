#include <iostream>
#include <queue>
#include <strings.h>
#include <vector>

using namespace std;
class Solution {
public:
  bool wordBreak(string s, vector<string> &wordDict) {
    vector<bool> v(s.size() + 1);
    queue<int> q_pos;
    q_pos.push(0);
    v[0] = true;
    while (!q_pos.empty()) {
      int cur_pos = q_pos.front();
      q_pos.pop();
      for (auto wd : wordDict) {
        if (cur_pos + wd.size() > s.size() || v[cur_pos + wd.size()])
          continue;
        string_view sv(s.data() + cur_pos,
                       wd.size()); // here is the error, s.data , not wd.data
        if (sv != wd)
          continue;
        if (cur_pos + wd.size() == s.size())
          return true;
        if (cur_pos + wd.size() < s.size()) {
          v[cur_pos + wd.size()] = true;
          q_pos.push(cur_pos + wd.size());
        }
      }
    }

    return v.back();
  }
};

int main() {
  Solution t;
  string ss = "leetcode";
  vector<string> wordDict = {"leet", "code"};
  ss = "ab";
  wordDict = {"a", "b"};
  ss = "applepenapple";
  wordDict = {"apple", "pen"};
  ss = "catsandog";
  wordDict = {"cats", "dog", "sand", "and", "cat"};
  cout << t.wordBreak(ss, wordDict) << endl;
}
