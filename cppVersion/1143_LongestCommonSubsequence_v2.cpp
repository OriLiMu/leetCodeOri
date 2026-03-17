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
    vector<vector<int>> v(s1.size() + 1, vector<int>(s2.size() + 1));
    for (int i = 1; i <= s1.size(); ++i) {
      for (int k = 1; k <= s2.size(); ++k) {
        if (s1[i - 1] == s2[k - 1]) { // 注意这个-1很容易出错
          v[i][k] = v[i - 1][k - 1] + 1;
        } else
          v[i][k] = max(v[i][k - 1], v[i - 1][k]);
        // 这里没处理else 导致断行
      }
    }

    return v[s1.size()][s2.size()];
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
