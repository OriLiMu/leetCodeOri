#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

class Solution {
public:
  int func(int n, int lastRightEdge, int remainLoopCnt,
           vector<vector<int>> &mem) {
    if (mem[remainLoopCnt][lastRightEdge]) {
      return mem[remainLoopCnt][lastRightEdge];
    }
    if (remainLoopCnt == 2) {
      mem[remainLoopCnt][lastRightEdge] = n - lastRightEdge;
      return mem[remainLoopCnt][lastRightEdge];
    }

    if (remainLoopCnt == 1) {
      mem[remainLoopCnt][lastRightEdge] = 1;
      return mem[remainLoopCnt][lastRightEdge];
    }

    int sum = 0;
    for (int i = lastRightEdge; i < n; i++) {
      sum += func(n, i, remainLoopCnt - 1, mem);
    }

    mem[remainLoopCnt][lastRightEdge] = sum;
    return sum;
  }

  int uniquePaths(int m, int n) {
    int result = 0;
    vector mem(m, vector<int>(n));
    return func(n, 0, m, mem);
  }
};

int main() {
  Solution s;
  cout << s.uniquePaths(7, 2) << endl;
}
