#include <algorithm>
#include <climits>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int maxCount(int m, int n, vector<vector<int>> &ops) {
    int width = m;
    int height = n;
    for (vector<int> op : ops) {
      if (op.size() < 2)
        continue;
      if (op[0] < width)
        width = op[0];
      if (op[1] < height)
        height = op[1];
    }

    return height * width;
  }
};

int main() {
  Solution s;
  // m = 3, n = 3, ops = []
  vector<vector<int>> ops = {};
  cout << s.maxCount(3, 3, ops) << endl;
  return 0;
}
