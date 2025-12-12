#include <algorithm>
#include <climits>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <iterator>
#include <queue>
#include <strings.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
class Solution {
public:
  vector<int> l1, l2;
  void dfs(vector<string> &cur, string &s, int leftIdx,
           vector<vector<string>> &r) {
    // for (auto &s : cur) {
    //   cout << s << ", ";
    // }
    // cout << endl;

    if (leftIdx == s.size()) {
      r.push_back(cur);
      return;
    }

    for (int i = 0; i < l1.size(); i++) {
      if (l1[i] <= leftIdx && i >= leftIdx) {
        string t = s.substr(leftIdx, (i - leftIdx) * 2 + 1);
        cur.push_back(t);
        dfs(cur, s, i + i - leftIdx + 1, r);
        cur.pop_back();
      }
    }

    for (int i = 0; i + 1 < l2.size(); i++) {
      if (l2[i] <= leftIdx && i >= leftIdx) {
        string t = s.substr(leftIdx, (i - leftIdx + 1) * 2);
        cur.push_back(t);
        dfs(cur, s, i + 1 + i - leftIdx + 1, r);
        cur.pop_back();
      }
    }
  }

  vector<vector<string>> partition(string s) {
    int left, right;
    for (int i = 0; i < s.size(); ++i) {
      left = right = i;
      while (left >= 0 && right < s.size() && s[left] == s[right]) {
        left--;
        right++;
      }
      left++; // 至少会加一个
      l1.push_back(left);
    }

    for (int i = 0; i < s.size() - 1; ++i) {
      left = right = i;
      right++;
      if (s[left] != s[right]) {
        l2.push_back(s.size());
        continue;
      }

      while (left >= 0 && right < s.size() && s[left] == s[right]) {
        left--;
        right++;
      }
      left++; // 至少会加一个
      l2.push_back(left);
    }

    vector<vector<string>> r;
    vector<string> cur;
    dfs(cur, s, 0, r);
    return r;
  }
};
int main() {
  Solution s;
  vector<vector<string>> r;
  string t = "bb";
  r = s.partition(t);
}
