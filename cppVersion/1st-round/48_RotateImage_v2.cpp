#include <algorithm>
#include <climits>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
class Solution {
public:
  void rotate(vector<vector<int>> &matrix) {
    int startRow = 0, startCol = 0, len = matrix.size() - 1;
    while (startRow < matrix.size() / 2) {
      int curRow = startRow, curCol = startCol;
      for (int i = 0; i < len; i++) {
        int tmp = matrix[curRow][curCol];
        curRow = curCol;
        curCol = startCol + len; // curRow依赖于curCol,所以 curCol后面在改变
        cout << "curRow: " << curRow << "curCol: " << curCol << endl;
        swap(tmp, matrix[curRow][curCol]);

        curCol = startCol + len - curRow - 1;
        curRow = startRow + len;
        swap(tmp, matrix[curRow][curCol]);

        curRow = curCol;
        curCol = startCol;
        swap(tmp, matrix[curRow][curCol]);

        curCol = startCol + len - curRow - 1;
        curRow = startRow;
        swap(tmp, matrix[curRow][curCol]);

        curCol++;
      }

      startRow++;
      startCol++;
      len -= 2;
    }
  }
};
int main() {
  Solution s;
  vector<vector<int>> vv = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  // vv = {{5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};

  s.rotate(vv);
  for (auto v : vv) {
    for (auto n : v)
      cout << n << ", ";
    cout << endl;
  }
}
