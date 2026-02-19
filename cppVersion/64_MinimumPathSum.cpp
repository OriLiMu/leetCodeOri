#include <iostream>
#include <strings.h>
#include <vector>

using namespace std;
class Solution {
public:
  int minPathSum(vector<vector<int>> &grid) {
    vector<vector<int>> v(grid.size(), vector<int>(grid[0].size()));
    v[0][0] = grid[0][0];
    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[0].size(); j++) {
        if (i == 0 && j == 0)
          continue;
        else if (i == 0)
          v[i][j] = v[i][j - 1] + grid[i][j];
        else if (j == 0)
          v[i][j] = v[i - 1][j] + grid[i][j];
        else
          v[i][j] = min(v[i - 1][j], v[i][j - 1]) + grid[i][j];
      }
    }

    return v[grid.size() - 1][grid[0].size() - 1];
  }
};
int main() {
  Solution s;
  vector<vector<int>> v = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
  v = {{1, 2, 3}, {4, 5, 6}};
  cout << s.minPathSum(v) << endl;
}
