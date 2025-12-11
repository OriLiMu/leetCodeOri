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
  vector<int> dx = {-1, 1, 0, 0};
  vector<int> dy = {0, 0, -1, 1};
  bool dfs(vector<vector<char>> &board, int r, int c, int curIdx,
           string &targetWord) {
    if (board[r][c] != targetWord[curIdx])
      return false;
    if (curIdx == targetWord.size() - 1)
      return true;
    char t = board[r][c];
    board[r][c] = '.';
    for (int i = 0; i < 4; ++i) {
      int a = r + dx[i];
      int b = c + dy[i];
      if (a >= 0 && a < board.size() && b >= 0 && b < board[0].size())
        if (dfs(board, a, b, curIdx + 1, targetWord))
          return true;
    }
    board[r][c] = t;

    return false;
  }

  bool exist(vector<vector<char>> &board, string word) {
    for (int i = 0; i < board.size(); ++i) {
      for (int j = 0; j < board[0].size(); ++j) {
        if (dfs(board, i, j, 0, word))
          return true;
      }
    }

    return false;
  }
};

int main() {
  vector<vector<char>> b = {
      {'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
  Solution s;
  cout << s.exist(b, "ABCCED") << endl;
}
