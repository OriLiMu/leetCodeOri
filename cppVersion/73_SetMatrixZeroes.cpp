#include <algorithm>
#include <climits>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
  void setZeroes(vector<vector<int>> &matrix) {
    bool firstRow = false;
    bool firstCol = false;
    for (int r = 0; r < matrix.size(); r++) {
      for (int c = 0; c < matrix[0].size(); c++) {
        if (matrix[r][c] == 0) {
          matrix[r][0] = 0;
          matrix[0][c] = 0;
          if (r == 0) {
            firstRow = true;
          }
          if (c == 0) {
            firstCol = true;
          }
        }
      }
    }
    for (int r = 1; r < matrix.size(); r++) {
      if (matrix[r][0] == 0) {
        for (int c = 1; c < matrix[0].size(); c++) {
          matrix[r][c] = 0;
        }
      }
    }
    for (int c = 1; c < matrix[0].size(); c++) {
      if (matrix[0][c] == 0) {
        for (int r = 1; r < matrix.size(); r++) {
          matrix[r][c] = 0;
        }
      }
    }
    if (firstRow) {
      for (int c = 1; c < matrix[0].size(); c++) {
        matrix[0][c] = 0;
      }
    }
    if (firstCol) {
      for (int r = 1; r < matrix.size(); r++) {
        matrix[r][0] = 0;
      }
    }
  }
};
int main() {
  Solution s;
  vector<vector<int>> mat = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
  s.setZeroes(mat);
  for (auto v : mat) {
    for (auto n : v) {
      cout << n << " ";
    }
    cout << endl;
  }
}
