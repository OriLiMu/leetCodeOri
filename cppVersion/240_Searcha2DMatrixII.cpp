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
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int row = 0, col = matrix[0].size() - 1;
    while (row < matrix.size() && col >= 0) {
      if (matrix[row][col] == target)
        return true;
      else if (matrix[row][col] > target)
        col--;
      else
        row++;
    }

    return false;
  }
};
int main() {
  Solution s;
  cout << "hello" << endl;
}
