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
  // 这个代码有越界的错误, 没想到为什么
  void func(int r, int c, vector<vector<int>> &visited,
            vector<vector<char>> &grid) {
    // 这里开始忽略了一个visited的判断
    if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() ||
        visited[r][c])
      return;
    visited[r][c] = 1;
    if (grid[r][c] == '1') {
      func(r - 1, c, visited, grid);
      func(r + 1, c, visited, grid);
      func(r, c - 1, visited, grid);
      func(r, c + 1, visited, grid);
    }
  };

  int numIslands(vector<vector<char>> &grid) {
    vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));
    int result = 0;
    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[0].size(); j++) {
        if (visited[i][j] == 0 && grid[i][j] == '1') {
          result++;
          func(i, j, visited, grid);
        }
      }
    }

    return result;
  }
};
int main() {
  Solution s;
  cout << "hello" << endl;
}
