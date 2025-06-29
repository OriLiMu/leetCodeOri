#include <algorithm>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstddef>
#include <cstdlib>
#include <filesystem>
#include <iostream>
#include <vector>

using namespace std;

// find max divisor then divide
class Solution {

public:
  struct ExpInfo {
    int value;
    int exp;
  };

  ExpInfo findNearestDivisor(int dividend, int divisor) {
    if (divisor < dividend) {
      return {0, 0};
    }

    int exp = 1;
    int n = divisor;
    int lastN = 0;
    int lastExp = 0;

    while (n >= dividend) {
      lastN = n;
      lastExp = exp;
      if (INT_MIN - n > n)
        break;
      n += n;
      if (INT_MAX - exp < exp)
        break;
      cout << exp << endl;
      exp += exp;
    }

    return {lastN, lastExp};
  }

  int divide(int dividend, int divisor) {
    int result = 0;
    bool isDiffSign = false;
    if ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0)) {
      isDiffSign = true;
    }

    if (divisor == 1)
      return dividend;
    if (divisor == -1) {
      if (dividend == INT_MIN)
        return INT_MAX;
      return -dividend;
    }

    divisor = divisor > 0 ? -divisor : divisor;
    dividend = dividend > 0 ? -dividend : dividend;

    while (dividend <= divisor) {
      ExpInfo expInfo = findNearestDivisor(dividend, divisor);
      dividend -= expInfo.value;
      cout << dividend << endl;
      result += expInfo.exp;
    }

    if (isDiffSign)
      result = 0 - result;

    return result;
  }
};

int main() {
  Solution s;
  cout << s.divide(-2147483648, -1) << endl;
}

