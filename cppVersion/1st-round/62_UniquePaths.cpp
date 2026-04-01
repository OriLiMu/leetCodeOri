#include <iostream>
#include <strings.h>
#include <vector>

using namespace std;
class Solution {
public:
  int uniquePaths(int m, int n) {
    if (m == 1 || n == 1)
      return 1;
    vector<vector<int>> mat(m, vector<int>(n, -1));
    mat[0][0] = 0, mat[0][1] = 1, mat[1][0] = 1;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (mat[i][j] == -1) {
          if (i == 0)
            mat[i][j] = mat[i][j - 1];
          else if (j == 0)
            mat[i][j] = mat[i - 1][j];
          else
            mat[i][j] = mat[i - 1][j] + mat[i][j - 1];
        }
      }
    }
    return mat[m - 1][n - 1];
  }
};

int main() {
  Solution s;
  int m = 3, n = 7;
  cout << s.uniquePaths(m, n) << endl;
}
