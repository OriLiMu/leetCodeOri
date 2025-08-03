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
  vector<int> spiralOrder(vector<vector<int>> &matrix) {
    int curCol = 0;
    int curRow = 0;
    int left = 0, right = matrix[0].size() - 1,
        top = 1, // 这个top = 1还是有点意思
        btm = matrix.size() - 1;
    vector<int> r;
    int cnt = 0;
    while (cnt <= matrix.size() * matrix[0].size()) {
      while (curCol <= right) { // size_t 减法错误
        r.push_back(matrix[curRow][curCol++]);
        cnt++;
      }
      if (cnt == matrix.size() * matrix[0].size())
        return r;
      right--;
      curRow++;
      curCol--;

      while (curRow <= btm) {
        r.push_back(matrix[curRow++][curCol]);
        cnt++;
      }
      if (cnt == matrix.size() * matrix[0].size())
        return r;
      btm--;
      curCol--;
      curRow--;

      while (curCol >= left) {
        r.push_back(matrix[curRow][curCol--]);
        cnt++;
      }
      if (cnt == matrix.size() * matrix[0].size())
        return r;
      left++;
      curRow--;
      curCol++;

      while (curRow >= top) {
        r.push_back(matrix[curRow--][curCol]);
        cnt++;
      }
      if (cnt == matrix.size() * matrix[0].size())
        return r;
      top++;
      curCol++;
      curRow++;
    }

    return r;
  }
};
int main() {
  Solution s;
  vector<vector<int>> m = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  m = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
  for (auto n : s.spiralOrder(m)) {
    cout << n << ", ";
  }
  cout << endl;
}
