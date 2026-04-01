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
  vector<int> dx = {1, -1, 0, 0}, dy = {0, 0, 1, -1};
  bool dfs(vector<vector<char>> &board, int r, int c, string &word, int idx) {
    if (board[r][c] != word[idx])
      return false;
    if (idx == word.size() - 1)
      return true;
    char t = board[r][c];
    board[r][c] = '.';
    for (int i = 0; i < 4; ++i) {
      int a = dy[i] + r, b = dx[i] + c;
      if (a >= 0 && a < board.size() && b >= 0 && b < board[0].size() &&
          board[a][b] != '.')
        if (dfs(board, a, b, word, idx + 1))
          return true;
    }
    board[r][c] = t;

    return false;
  }

  bool exist(vector<vector<char>> &board, string word) {
    for (int i = 0; i < board.size(); ++i)
      for (int k = 0; k < board[0].size(); ++k) {
        if (dfs(board, i, k, word, 0))
          return true;
      }
    return false;
  }
};
int main() {
  Solution s;
  vector<vector<char>> b = {
      {'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};

  cout << s.exist(b, "ABCCED");
}
