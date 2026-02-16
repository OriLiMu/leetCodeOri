#include <climits>
#include <cmath>
#include <iostream>
#include <strings.h>
#include <vector>

using namespace std;
class Solution {
public:
  int r = INT_MAX;

  bool isSquareNum(int n) {
    if (n < 0)
      return false;
    int r = sqrt(n);
    return r * r == n;
  }

  void func(int n, int step_cnt) {
    if (step_cnt > r)
      return;
    if (isSquareNum(n)) {
      r = min(step_cnt + 1, r);
      return;
    }
    int e = int(sqrt(n));
    for (int i = 1; i <= e; i++)
      func(n - i * i, step_cnt + 1);
  }

  int numSquares(int n) {
    func(n, 0);
    return r;
  }
};

int main() {
  Solution s;
  int n = 12;
  cout << s.numSquares(n) << endl;
}
