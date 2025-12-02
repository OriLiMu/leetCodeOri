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
  bool func(vector<vector<char>> &board, string &word, string &cur,
            vector<int> &curPath, int r, int c, int rowCnt, int colCnt) {
    // if (cur == "ABEDCB") {
    if (cur == "A") {
      cout << "here" << endl;
    }
    cout << cur << endl;
    if (cur == word)
      return true;

    // 下面这个逻辑我理解的是合并不了, 需要单独的处理
    // go up 有效性检验
    if (r - 1 >= 0) {
      int upIdx = (r - 1) * colCnt + c;
      char upChar = board[r - 1][c];
      if (upChar == word[cur.size()] &&
          find(curPath.begin(), curPath.end(), upIdx) == curPath.end()) {
        cur.push_back(upChar);
        curPath.push_back(upIdx);
        if (func(board, word, cur, curPath, r - 1, c, rowCnt, colCnt))
          return true;
        cur.pop_back();
        curPath.pop_back();
      }
    }

    if (r + 1 < rowCnt) {
      int downIdx = (r + 1) * colCnt + c;
      char downChar = board[r + 1][c];
      if (downChar == word[cur.size()] &&
          find(curPath.begin(), curPath.end(), downIdx) == curPath.end()) {
        cur.push_back(downChar);
        curPath.push_back(downIdx);
        if (func(board, word, cur, curPath, r + 1, c, rowCnt, colCnt))
          return true;
        cur.pop_back();
        curPath.pop_back();
      }
    }

    if (c - 1 >= 0) {
      int leftIdx = r * colCnt + c - 1;
      char leftChar = board[r][c - 1];
      if (leftChar == word[cur.size()] &&
          find(curPath.begin(), curPath.end(), leftIdx) == curPath.end()) {
        cur.push_back(leftChar);
        curPath.push_back(leftIdx);
        if (func(board, word, cur, curPath, r, c - 1, rowCnt, colCnt))
          return true;
        cur.pop_back();
        curPath.pop_back();
      }
    }

    if (c + 1 < colCnt) {
      int rightIdx = r * colCnt + c + 1;
      char rightChar = board[r][c + 1];
      if (rightChar == word[cur.size()] &&
          find(curPath.begin(), curPath.end(), rightIdx) == curPath.end()) {
        cur.push_back(rightChar);
        curPath.push_back(rightIdx);
        if (func(board, word, cur, curPath, r, c + 1, rowCnt, colCnt))
          return true;
        cur.pop_back();
        curPath.pop_back();
      }
    }

    return false;
  }

  bool exist(vector<vector<char>> &board, string word) {
    int r = board.size();
    int c = board[0].size();
    string cur;
    vector<int> curPath;
    for (int i = 0; i < r; ++i) {
      for (int j = 0; j < c; ++j) {
        // 没有验证
        cur.push_back(board[i][j]);
        curPath.push_back(i * r + j);
        if (func(board, word, cur, curPath, i, j, r, c))
          return true;
        cur.pop_back();
        curPath.pop_back();
      }
    }

    return false;
  }
};

int main() {
  Solution s;
  vector<vector<char>> b = {{'Z', 'Z', 'Z', 'Z', 'Z'},
                            {'Z', 'C', 'B', 'A', 'B'},
                            {'A', 'D', 'E', 'D', 'C'},
                            {'B', 'E', 'Z', 'Z', 'Z'}};
  cout << s.exist(b, "ABEDCBA") << endl;
}
