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
  vector<vector<string>> result;
  unordered_map<int, int> usedRow;
  int msize;
  void dfs(int c) {
    if (c == msize) {
      vector<string> ans(msize, string(msize, '.'));
      int idx = 0;
      for (auto &r : usedRow)
        ans[r.first][idx++] = 'Q';

      result.push_back(ans);
      return;
    }

    for (int r = 0; r < msize; ++r) {
      // 直线判断
      if (usedRow.find(r) == usedRow.end()) {
        bool isOnDiagonal = false;
        for (auto &ur : usedRow) {
          if (abs(ur.first - r) == abs(ur.second - c)) {
            isOnDiagonal = true;
            break;
          }
        }

        if (!isOnDiagonal) {
          usedRow.insert({r, c});
          dfs(c + 1);
          usedRow.erase(r);
        }
      }
    }
  }

  vector<vector<string>> solveNQueens(int n) {
    msize = n;
    dfs(0);
    return result;
  }
};
int main() {
  Solution s;
  vector<vector<string>> r = s.solveNQueens(4);
  for (auto &vs : r) {
    for (auto &s : vs) {
      cout << s << endl;
    }
    cout << endl;
  }
}
