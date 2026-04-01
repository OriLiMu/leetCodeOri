#include <algorithm>
#include <climits>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
  bool isValidSudoku(vector<vector<char>> &board) {
    vector<int> row(9, 0);
    vector<int> col(9, 0);
    vector<int> square(9, 0);
    for (int r = 0; r < 9; r++) {
      for (int c = 0; c < 9; c++) {
        if (board[r][c] != '.') {
          int n = 1 << (board[r][c] - '0');
          if (row[r] & n || col[c] & n || square[r / 3 * 3 + c / 3] & n) {
            return false;
          } else {
            row[r] |= n;
            col[c] |= n;
            square[r / 3 * 3 + c / 3] |= n;
          }
        }
      }
    }

    return true;
  }
};
int main() {
  Solution s;
  vector<vector<char>> board = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                                {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                                {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                                {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                                {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                                {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                                {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                                {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                                {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
  cout << s.isValidSudoku(board) << endl;
}
