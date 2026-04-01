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
    for (int i = 1; i < matrix.size(); i++) {
      for (int k = 0; k < i; k++) {
        swap(matrix[i][k], matrix[k][i]);
      }
    }

    for (int i = 0; i < matrix.size(); i++) {
      for (int j = 0; j < matrix.size() / 2; j++) {
        swap(matrix[i][j], matrix[i][matrix.size() - 1 - j]);
      }
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
