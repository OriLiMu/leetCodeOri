#include <algorithm>
#include <climits>
#include <cmath>
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int divide(int dividend, int divisor) {
    // index value count
    vector<vector<int>> expVec = {{0, 0, 0}, {1, divisor, 0}};
    int curDividend = dividend;
    bool reachMax = false;
    int curIndex = 1;
    int curDivisor = divisor;

    if (dividend < divisor) {
      return 0;
    }
    if (dividend == divisor) {
      return 1;
    }

    // find max divisor
    while (curDividend - curDivisor > 0) {
      if (expVec.size() < curIndex + 1) {
        expVec.push_back({curIndex, curDivisor, 0});
      }
      curIndex++;
      curDivisor += curDivisor;
    }

    curIndex--;
    curDivisor = expVec[curIndex][1];

    while (true) {
      while (curDividend - curDivisor >= 0) {
        curDividend -= curDivisor;
        expVec[curIndex][2]++;
      }
      curIndex--;
      if (curIndex < 1) {
        break;
      }

      curDivisor = expVec[curIndex][1];
    }
    int result = 0;
    for (vector<int> vec : expVec) {
      for (int i = 0; i < vec[2]; i++) {
        result += vec[0];
      }
    }

    return result;
  }
};

int main() {
  Solution s;
  cout << s.divide(10, 3) << endl;
}
