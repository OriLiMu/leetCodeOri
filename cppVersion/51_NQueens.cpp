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
  vector<int> usedRow;
  int msize;
  void dfs(int c) {
    if (c == msize) {
      vector<string> ans(msize, string(msize, '.'));
      for (int i = 0; i < msize; ++i) {
        ans[usedRow[i]][i] = 'Q';
      }

      result.push_back(ans);
      return;
    }

    for (int r = 0; r < msize; ++r) {
      if (find(usedRow.begin(), usedRow.end(), r) == usedRow.end()) {
        usedRow.push_back(r);
        dfs(c + 1);
        usedRow.pop_back();
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
  cout << "hello" << endl;
}
