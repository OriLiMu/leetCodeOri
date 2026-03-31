#include <iostream>
#include <strings.h>
#include <vector>

using namespace std;
class Solution {
public:
  int minDistance(string s1, string s2) {
    if (!s1.size() || !s2.size())
      return max(s1.size(), s2.size());
    vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1));
    for (int i = 0; i <= s1.size(); i++)
      dp[i][0] = i;
    for (int i = 1; i <= s2.size(); i++)
      dp[0][i] = i;
    for (int i = 1; i <= s1.size(); i++) {
      for (int k = 1; k <= s2.size(); k++) {
        // 这里应该-1, 这个是很容易犯的错误
        if (s1[i - 1] == s2[k - 1])
          dp[i][k] = dp[i - 1][k - 1];
        else {
          // insert
          // int t = min(dp[i - 1][k], dp[i][k - 1]) + 1;
          // remove 这一步理解比较有意思, 就是类似于哪个烧水的数学思想,
          // 既然当前的char不相等, 那么删掉之后回到之前的状态,
          // 发现这种处理方法和上面的insert的一样, 所以可以省略
          // dp[i][k] = min(dp[i - 1][k], dp[i][k - 1]) + 1;
          // change
          dp[i][k] = min(dp[i - 1][k - 1], min(dp[i - 1][k], dp[i][k - 1])) + 1;
        }
      }
    }

    for (const auto &row : dp) {
      for (const auto &elem : row) {
        cout << elem << " ";
      }
      cout << endl;
    }
    return dp[s1.size()][s2.size()];
  }
};

int main() {
  Solution s;
  string s1 = "horse";
  string s2 = "ros";
  s1 = "intention";
  s2 = "execution";
  // 这个报错, 没考虑空串, 需要特殊处理
  s1 = "";
  s2 = "anything";

  // 初始值定义错了
  s1 = "plasma";
  s2 = "altruism";

  cout << s.minDistance(s1, s2) << endl;
}
