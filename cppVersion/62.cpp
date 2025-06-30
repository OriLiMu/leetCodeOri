#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int func(int m, int lastRightEdge, int remainLoopCnt) {
    if (remainLoopCnt == 0) {
      return m - lastRightEdge;
    }

    int sum = 0;
    for (int i = lastRightEdge; i < m; i++) {
      sum += func(m, i, remainLoopCnt - 1);
    }
    return sum;
  }

  int uniquePaths(int m, int n) { return func(m, 0, n); }
};

int main() { Solution s; }
