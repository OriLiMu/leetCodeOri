#include <iostream>
#include <strings.h>
#include <vector>

using namespace std;
class Solution {
public:
  string longestPalindrome(string s) {
    vector<vector<bool>> v(s.size(), vector<bool>(s.size()));
    int r = 1;
    int si = 0, lr = 1;
    for (int i = 0; i < s.size() - 1; ++i) {
      v[i][i] = true;
      if (s[i] == s[i + 1]) {
        v[i][i + 1] = true;
        si = i;
        lr = 2;
      }
    }
    for (int l = 3; l <= s.size(); l++) {
      for (int i = 0; i < s.size() - 1; i++) {
        if (i + l <= s.size()) {
          if ((v[i + 1][i + l - 2] || v[i + l - 2][i + 1]) &&
              s[i] == s[i + l - 1]) {
            v[i][i + l - 1] = true;
            if (l > lr) {
              si = i;
              lr = l;
            }
          }
        }
      }
    }

    return s.substr(si, lr);
  }
};
int main() {
  Solution s;
  string str = "babad";
  str = "cbbd";
  cout << s.longestPalindrome(str) << endl;
}
