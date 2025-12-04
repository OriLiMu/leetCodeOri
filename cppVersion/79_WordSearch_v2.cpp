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
  bool dfs(vector<vector<char>> &board, int r, int c, int index,
           string &targetWord) {
    if (board[r][c] != targetWord[index])
      return false;
    if (index == targetWord.size() - 1)
      return true;
    char t = board[r][c];
    board[r][c] = '.';
    for (int i = 0; i < 4; ++i) {
      // if (r - 1 >= 0 && r + 1 < board.size() && c - 1 >= 0 &&  c + 1 <
      // board.size()) // 这个逻辑是错误的没必要全部的都在范围之内
      // 这个是一个关键的代码步骤. 也可能是理解的问题
      int a = r + dx[i];
      int b = c + dy[i];
      if (a >= 0 && a < board.size() && b >= 0 && b < board[0].size()) {
        // && board[a][b] == targetWord[index + 1]) { //
        // 这个也应该写到下一级里面, 谁的活谁处理 char tmp = board[a][b];
        // board[a][b] =
        //     '.'; // 这个如果你写到这里, 那么意味着你exist里面的也需要这么做,
        //          // 这是在给下一级的board修改字符
        if (dfs(board, a, b, index + 1, targetWord))
          return true;
        // board[a][b] = tmp; // recover the status
      }
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
  Solution s;
  cout << "hello" << endl;
}
