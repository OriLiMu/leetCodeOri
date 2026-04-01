#include <algorithm>
#include <climits>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <numeric>
#include <regex>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
class Solution {
public:
  void rotate(vector<vector<int>> &matrix) {
    int curMoveStep = matrix.size();
    int tmp = matrix.back().front();
    int startRow = 0, startCol = 0;
    int limit =
        matrix.size() % 2 == 0 ? matrix.size() / 2 - 1 : matrix.size() / 2;
    while (startRow <= limit) { // 这个limit的计算
      int curRow, curCol, tmpCurCol = startCol, len;
      for (int i = 0; i < curMoveStep - 1; i++) { //
        // right
        curRow = startRow;
        curCol = tmpCurCol; // 如果你在这里使用i, 那么后面就会有问题,
                            // 这个curMoveStep会变得, 上下左右的边界也会变化
        tmp = matrix[curRow][curCol];
        len = startCol + curMoveStep;
        // cout << "row:" << curRow << ", col: " << curCol << endl;
        curRow = curCol; // 这个相等的原因是因为, 此次的旋转方向和row,
                         // col计数方向一致
        // curCol = matrix.size() - 1;
        curCol = len - 1; // 注意间距比点少一个, startCol本身已经包含了一个长度

        // down
        // cout << "row:" << curRow << ", col: " << curCol << endl;
        swap(tmp, matrix[curRow][curCol]);
        // curCol = matrix.size() - 1 - curRow;
        // curRow = static_cast<int>(matrix.size()) - 1;
        curCol = len - curRow - 1 + startRow;
        curRow = len - 1;

        // left
        // cout << "row:" << curRow << ", col: " << curCol << endl;
        swap(tmp, matrix[curRow][curCol]);
        curRow = curCol;
        curCol = startCol;

        // top
        swap(tmp, matrix[curRow][curCol]);
        curCol = len - 1 - curRow + startCol;
        curRow = startRow;

        swap(tmp, matrix[startRow][tmpCurCol]);
        tmpCurCol++;
      }

      startRow++;
      startCol++;
      curMoveStep -= 2;
    }
  }
};
int main() {
  Solution s;
  vector<vector<int>> vv = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  vv = {{5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};

  s.rotate(vv);
  for (auto v : vv) {
    for (auto n : v)
      cout << n << ", ";
    cout << endl;
  }
}
