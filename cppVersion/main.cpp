#include <iostream>
#include <strings.h>
#include <vector>

using namespace std;
class Solution {
public:
  int longestCommonSubsequence(string text1, string text2) {
    vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1));

    for (int m = 0; m < text1.size(); ++m) {
      for (int k = 0; k < text2.size(); ++k) {
        // if (text1[m] == text2[k] && k > ce2) { // 错在把条件写在一起了
        if (text1[m] == text2[k]) {
          // 矛盾在于, 如果你跳了K, 那么之前的数据没有不全,
          // 如果你补全那么就是 3-nested
          // 错误的根源还是你想取巧
          int t = max(dp[m + 1][k], dp[m][k + 1]) + 1;
          for (int n = k; n < text2.size(); n++)
            dp[m + 1][n + 1] = t;
          break;
        } else
          dp[m + 1][k + 1] = max(dp[m + 1][k], dp[m][k + 1]);
      }
    }

    return dp[text1.size()][text2.size()];
  }
};
int main() {
  Solution s;
  string s1, s2;
  s1 = "abcba";
  s2 = "abcbcba";
  // s1 = "abcd";
  // s2 = "aced";
  cout << s.longestCommonSubsequence(s1, s2) << endl;
}
