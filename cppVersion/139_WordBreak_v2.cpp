#include <iostream>
#include <queue>
#include <strings.h>
#include <vector>

using namespace std;
class Solution {
public:
  bool wordBreak(string s, vector<string> &wordDict) {
    vector<bool> v(s.size() + 1);
    queue<int> pv;
    pv.push(0);
    while (!pv.empty()) {
      int cur_pos = pv.front();
      pv.pop();
      for (auto &wd : wordDict) {
        if (!string_view(s).substr(cur_pos).starts_with(wd) ||
            v[cur_pos + wd.size()])
          continue;
        v[cur_pos + wd.size()] = true;
        pv.push(cur_pos + wd.size());
      }
    }

    return v.back();
  }
};
int main() {
  Solution t;
  string s = "catsandog";
  vector<string> v = {"cats", "dog", "sand", "and", "cat"};
  cout << t.wordBreak(s, v) << endl;
}
