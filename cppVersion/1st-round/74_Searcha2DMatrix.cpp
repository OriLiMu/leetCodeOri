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
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    for (int i = matrix[0].size() - 1; i >= 0; --i) {
      if (matrix[0][i] <= target) {
        for (int k = 0; k < matrix.size(); ++k) {
          if (matrix[k][i] == target)
            return true;
        }
      }
    }

    return false;
  }
};
int main() {
  Solution s;
  cout << "hello" << endl;
}
