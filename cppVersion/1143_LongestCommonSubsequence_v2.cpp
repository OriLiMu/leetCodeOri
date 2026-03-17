#include <iostream>
#include <strings.h>
#include <vector>

using namespace std;
class Solution {
public:
  struct data {
    int l;
    bool iM;
  };

  int longestCommonSubsequence(string s1, string s2) {
    vector<vector<data>> v(s1.size() + 1, vector<data>(s2.size() + 1));
    for (int i = 1; i <= s1.size(); ++i) {
      bool isMtl = false;
      for (int k = 1; k <= s2.size(); ++k) {
        if (s1[i - 1] == s2[k - 1]) { // 注意这个-1很容易出错
          v[i][k].iM = true;
          v[i][k].l = v[i - 1][k - 1].l + 1;
          // isMtl = true;
        } else
          v[i][k].l = max(v[i][k - 1].l, v[i - 1][k].l);
        // 这里没处理else 导致断行
      }
    }

    for (const auto &row : v) {
      for (const auto &elem : row) {
        cout << elem.l << " ";
      }
      cout << endl;
    }

    return v[s1.size()][s2.size()].l;
  }
};

int main() {
  Solution s;
  string s1 = "kwvkwm";
  string s2 = "kwvkwkwm";
  // s1 = "abc";
  // s2 = "aec";
  // s1 = "abcde";
  // s2 = "ace";
  cout << s.longestCommonSubsequence(s1, s2) << endl;
}
