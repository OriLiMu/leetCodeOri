#include <algorithm>
#include <climits>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int divide(int dividend, int divisor) {
    int result = 0;
    int abs_dividend = abs(dividend);
    int abs_divisor = abs(divisor);
    while (abs_dividend - abs_divisor >= 0) {
      abs_dividend -= abs_divisor;
      result++;
    }
    if ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0)) {
      result = 0 - result;
    }

    if (result > INT_MAX) {
      return INT_MAX;
    } else if (result < INT_MIN) {
      return INT_MIN;
    }

    return result;
  }
};

int main() {
  Solution s;
  cout << s.divide(10, 3) << endl;
}
